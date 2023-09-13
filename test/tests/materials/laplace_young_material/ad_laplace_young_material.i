[Mesh]
  [mesh]
    type = GeneratedMeshGenerator
    dim = 2
    nx = 20
    ny = 20
  []
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
    type = ADMatReaction
    variable = u
    reaction_rate = -1
  []
[]

[BCs]
  [bc]
    type = ADMatNeumannBC
    variable = u
    boundary = 'top right left bottom'
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
