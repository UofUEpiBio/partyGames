#ifdef _OPENMP
#include <omp.h>
#endif

#include<random>

#include <RcppArmadillo.h>
using namespace Rcpp;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::plugins(openmp)]]


arma::mat monopoly(int maxTurns, int sides, int numDice);

// [[Rcpp::export]]
std::vector< std::vector< int > > simMonopoly(
    int numGames = 10,
    int maxTurns = 500,
    int sides = 6,
    int numDice = 2,
    int cores = 1
) {
  std::vector < std::vector< int > > results(numGames, std::vector<int>(40));


#ifdef _OPENMP
  // setting the cores
  omp_set_num_threads(cores);
#endif

#ifdef _OPENMP
  int effective_ncores = cores;
#else
  int effective_ncores = 1;
#endif

  std::vector< int > nreplicates(effective_ncores, 0);
  std::vector< int > nreplicates_csum(effective_ncores, 0);
  std::vector< int > start(effective_ncores, 0);
  std::vector< int > end(effective_ncores, numGames);
  int sums = 0u;
  for (int i = 0; i < effective_ncores; i++){
    nreplicates[i] = static_cast<int>(std::floor(numGames/effective_ncores));

    nreplicates_csum[i] = sums;

    sums += nreplicates[i];

  }

  if (sums < numGames) nreplicates[effective_ncores - 1] += (numGames - sums);

  for (int i = 0; i < effective_ncores; i++){
    start[i] = nreplicates_csum[i];
  }

  for (int i = 0; i < effective_ncores - 1; i++){
    end[i] = start[i + 1];
  }

  end[effective_ncores - 1] = numGames;


#pragma omp parallel
{

  auto iam = omp_get_thread_num();
  arma::mat game(2, 40);
  arma::rowvec gamerow = game.row(1);
  std::vector<int> vec(gamerow.begin(), gamerow.end());

#pragma omp parallel for shared(start, iam, game, gamerow end, numGames, effective_ncores, maxTurns, sides, numDice, results) default(none)
  for (int i = start[iam]; i < end[iam]; i++){

    for (int j = 0; j < 40; j++){

      game = monopoly(maxTurns, sides, numDice);
      gamerow = game.row(1);
      vec(gamerow.begin(), gamerow.end());

      results[i][j] = vec[j];
    }
  }
}


return results;

}

