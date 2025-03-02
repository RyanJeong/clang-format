#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

#define EXTREMELY_LONG_MACRO_NAME_USING_MULTIPLE_WORDS_AND_EXCEEDING_EIGHTY_COLUMNS( \
    a, b)                                                                            \
  ((a) + (b))
#define SIMPLE_MACRO(x) (x + 1)

template <typename TemplateParameterOne, typename TemplateParameterTwo,
          typename TemplateParameterThree>
struct
    ExtremelyLongNamedStructWithMultipleTemplateParametersToTestWrappingRules {
  TemplateParameterOne first_field;
  TemplateParameterTwo second_field;
  TemplateParameterThree third_field;
  ExtremelyLongNamedStructWithMultipleTemplateParametersToTestWrappingRules(
      TemplateParameterOne a, TemplateParameterTwo b, TemplateParameterThree c)
      : first_field(a), second_field(b), third_field(c) {}
};

template <typename TypeAlpha, typename TypeBeta>
TypeAlpha VeryLongFunctionNameThatWillForceWrappingInManyStyleGuides(
    TypeAlpha alpha_value, TypeBeta beta_value, TypeAlpha gamma_value,
    TypeBeta delta_value, TypeAlpha epsilon_value) {
  return alpha_value + gamma_value + epsilon_value;
}

static int AnotherFunctionWithTooManyParametersToTestLineBreaksAndIndentation(
    int param_one, int param_two, int param_three, int param_four,
    int param_five, int param_six, int param_seven, int param_eight,
    int param_nine) {
  return param_one + param_two + param_three + param_four + param_five +
         param_six + param_seven + param_eight + param_nine;
}

int main() {
  ExtremelyLongNamedStructWithMultipleTemplateParametersToTestWrappingRules<
      int, double, std::string>
      inst(1, 2.5, "teststring");
  std::cout << inst.first_field << std::endl;
  std::cout << inst.second_field << std::endl;
  std::cout << inst.third_field << std::endl;
  int x = VeryLongFunctionNameThatWillForceWrappingInManyStyleGuides<int, int>(
      10, 20, 30, 40, 50);
  x = AnotherFunctionWithTooManyParametersToTestLineBreaksAndIndentation(
      1, 2, 3, 4, 5, 6, 7, 8, 9);
  std::cout << x << std::endl;
  std::cout
      << EXTREMELY_LONG_MACRO_NAME_USING_MULTIPLE_WORDS_AND_EXCEEDING_EIGHTY_COLUMNS(
             10, 20)
      << std::endl;
  std::map<std::string, int> long_map;
  long_map
      ["some_very_long_key_to_force_wrapping_and_check_formatting_"
       "behavior"] = 100;
  for (auto& kv : long_map) { std::cout << kv.first << kv.second << std::endl; }
  return 0;
}

inline void AnotherInlineFunctionWithALongNameAndManyParams(
    std::string paramAlpha, std::string paramBeta, std::string paramGamma,
    std::string paramDelta, std::string paramEpsilon) {
  std::cout << paramAlpha << paramBeta << paramGamma << paramDelta
            << paramEpsilon << std::endl;
}

static void LongIdentifierLoopTest() {
  for (int super_long_index_variable_name_for_iteration = 0;
       super_long_index_variable_name_for_iteration < 3;
       super_long_index_variable_name_for_iteration++) {}
}

inline int OperationWithLongArgNames(
    int alphaBetaGammaDelta, int epsilonZetaEtaTheta,
    int iotaKappaLambdaMuNuXiOmicronPiRhoSigmaTau) {
  return alphaBetaGammaDelta + epsilonZetaEtaTheta +
         iotaKappaLambdaMuNuXiOmicronPiRhoSigmaTau;
}

struct NestedLongStructWithMultipleLevels {
  struct SubLevelStruct {
    int a;
  };
  SubLevelStruct field;
  explicit NestedLongStructWithMultipleLevels(int v) { field.a = v; }
};

template <typename T>
struct AnotherLongTemplate {
  T data;
  explicit AnotherLongTemplate(T x) : data(x) {}
};

static void UseNestedLongStruct() {
  NestedLongStructWithMultipleLevels obj(123);
  AnotherLongTemplate<std::string> t("LongStringValueForTestingLineBreak");
  std::cout << obj.field.a << t.data << std::endl;
}
