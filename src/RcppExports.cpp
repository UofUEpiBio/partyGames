// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

#ifdef RCPP_USE_GLOBAL_ROSTREAM
Rcpp::Rostream<true>&  Rcpp::Rcout = Rcpp::Rcpp_cout_get();
Rcpp::Rostream<false>& Rcpp::Rcerr = Rcpp::Rcpp_cerr_get();
#endif

// diceSum
int diceSum(int sides, int numDice);
RcppExport SEXP _partyGames_diceSum(SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(diceSum(sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// dieElephant
List dieElephant(int n, int sides, int numDice);
RcppExport SEXP _partyGames_dieElephant(SEXP nSEXP, SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(dieElephant(n, sides, numDice));
    return rcpp_result_gen;
END_RCPP
}
// leftRightElephant
List leftRightElephant(int n, double pheads);
RcppExport SEXP _partyGames_leftRightElephant(SEXP nSEXP, SEXP pheadsSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type pheads(pheadsSEXP);
    rcpp_result_gen = Rcpp::wrap(leftRightElephant(n, pheads));
    return rcpp_result_gen;
END_RCPP
}
// lrDieElephant
List lrDieElephant(int n, double pheads, int sides, int numDice);
RcppExport SEXP _partyGames_lrDieElephant(SEXP nSEXP, SEXP pheadsSEXP, SEXP sidesSEXP, SEXP numDiceSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type n(nSEXP);
    Rcpp::traits::input_parameter< double >::type pheads(pheadsSEXP);
    Rcpp::traits::input_parameter< int >::type sides(sidesSEXP);
    Rcpp::traits::input_parameter< int >::type numDice(numDiceSEXP);
    rcpp_result_gen = Rcpp::wrap(lrDieElephant(n, pheads, sides, numDice));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_partyGames_diceSum", (DL_FUNC) &_partyGames_diceSum, 2},
    {"_partyGames_dieElephant", (DL_FUNC) &_partyGames_dieElephant, 3},
    {"_partyGames_leftRightElephant", (DL_FUNC) &_partyGames_leftRightElephant, 2},
    {"_partyGames_lrDieElephant", (DL_FUNC) &_partyGames_lrDieElephant, 4},
    {NULL, NULL, 0}
};

RcppExport void R_init_partyGames(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
