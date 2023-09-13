#pragma once

#include "Material.h"

template <bool is_ad>
class LaplaceYoungMaterialTempl : public Material
{
public:
  static InputParameters validParams();

  LaplaceYoungMaterialTempl(const InputParameters & parameters);

  virtual void computeQpProperties() override;

protected:
  const GenericVariableGradient<is_ad> & _grad_u;
  GenericMaterialProperty<Real, is_ad> & _property;
};

typedef LaplaceYoungMaterialTempl<false> LaplaceYoungMaterial;
typedef LaplaceYoungMaterialTempl<true> ADLaplaceYoungMaterial;
