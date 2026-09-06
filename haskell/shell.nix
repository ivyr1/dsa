{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
    packages = [
      pkgs.ghc
      pkgs.haskell-language-server
      pkgs.cabal-install
      pkgs.hlint
      pkgs.fourmolu
    ];

  shellHook = ''
    echo "GHC version: $(ghc --version)"
  '';
}
