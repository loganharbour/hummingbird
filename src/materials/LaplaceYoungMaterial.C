//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "LaplaceYoungMaterial.h"

registerMooseObject("HummingbirdApp", LaplaceYoungMaterial);
registerMooseObject("HummingbirdApp", ADLaplaceYoungMaterial);

template <bool is_ad>
InputParameters
LaplaceYoungMaterialTempl<is_ad>::validParams()
{
  InputParameters params = Material::validParams();
  params.addRequiredCoupledVar("variable", "The variable to use");
  return params;
}

template <bool is_ad>
LaplaceYoungMaterialTempl<is_ad>::LaplaceYoungMaterialTempl(const InputParameters & parameters)
  : Material(parameters),
    _grad_u(coupledGenericGradient<is_ad>("variable")),
    _property(declareGenericProperty<Real, is_ad>("k"))
{
}

template <bool is_ad>
void
LaplaceYoungMaterialTempl<is_ad>::computeQpProperties()
{
  _property[_qp] = 1.0 / std::sqrt(1 + _grad_u[_qp] * _grad_u[_qp]);
}

template class LaplaceYoungMaterialTempl<false>;
template class LaplaceYoungMaterialTempl<true>;
