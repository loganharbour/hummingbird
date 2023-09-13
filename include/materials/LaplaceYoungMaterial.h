#pragma once

#include "Material.h"

template <bool is_ad>
class LaplaceYoungMaterialTempl : public Material
{
public:
  static InputParameters validParams();

  LaplaceYoungMaterialTempl(const InputParameters & parameters);

protected:
  virtual void computeQpProperties() override;

  /// The material property that we are defining
  GenericMaterialProperty<Real, is_ad> & _k;

  /// The gradient of the variable
  const GenericVariableGradient<is_ad> & _grad_u;
};

typedef LaplaceYoungMaterialTempl<false> LaplaceYoungMaterial;
typedef LaplaceYoungMaterialTempl<true> ADLaplaceYoungMaterial;
