#include "LaplaceYoungMaterial.h"

registerMooseObject("HummingbirdApp", LaplaceYoungMaterial);
registerMooseObject("HummingbirdApp", ADLaplaceYoungMaterial);

template <bool is_ad>
InputParameters
LaplaceYoungMaterialTempl<is_ad>::validParams()
{
  InputParameters params = Material::validParams();
  params.addRequiredCoupledVar("variable", "The variable that is used in the computation of k");
  return params;
}

template <bool is_ad>
LaplaceYoungMaterialTempl<is_ad>::LaplaceYoungMaterialTempl(const InputParameters & parameters)
  : Material(parameters),
    _k(declareGenericProperty<Real, is_ad>("k")),
    _grad_u(coupledGenericGradient<is_ad>("variable"))
{
}

template <bool is_ad>
void
LaplaceYoungMaterialTempl<is_ad>::computeQpProperties()
{
  _k[_qp] = 1 / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
}

template class LaplaceYoungMaterialTempl<false>;
template class LaplaceYoungMaterialTempl<true>;
