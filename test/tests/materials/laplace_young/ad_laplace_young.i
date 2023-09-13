[Mesh/gmg]
  type = GeneratedMeshGenerator
  dim = 2
  nx = 100
  ny = 100
[]

[Variables/u]
[]

[Kernels]
  [diffusion]
    type = ADMatDiffusion
    variable = u
    diffusivity = k
  []
  [reaction]
    type = ADReaction
    variable = u
  []
[]

[BCs]
  [neumann]
    type = ADMatNeumannBC
    variable = u
    boundary = 'top right bottom left'
    boundary_material = k
    value = 0.2
  []
[]

[Materials/laplace_young]
  type = ADLaplaceYoungMaterial
  variable = u
[]

[Executioner]
  type = Steady
  solve_type = 'NEWTON'
  petsc_options_iname = '-pc_type -pc_hypre_type'
  petsc_options_value = 'hypre boomeramg'
[]

[Outputs]
  exodus = true
[]
