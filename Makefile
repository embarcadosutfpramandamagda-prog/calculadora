.PHONY: all test run clean limites prevencao perfis web

all: test

# Executa todos os 26 testes unitarios via CTest
test:
	cmake -S . -B build
	cmake --build build
	ctest --test-dir build --output-on-failure

# Executa o simulador no terminal
run:
	cmake -S . -B build
	cmake --build build --target cli_financiamento
	./build/cli_financiamento

# Executa apenas os testes de limites
limites:
	cmake -S . -B build
	cmake --build build --target testes_financiamento
	./build/testes_financiamento "--gtest_filter=Limites.*"

# Executa apenas os testes de prevencao
prevencao:
	cmake -S . -B build
	cmake --build build --target testes_financiamento
	./build/testes_financiamento "--gtest_filter=Prevencao.*"

# Executa apenas os testes de perfis
perfis:
	cmake -S . -B build
	cmake --build build --target testes_financiamento
	./build/testes_financiamento "--gtest_filter=Perfis.*"

clean:
	rm -rf build build_cmake

# Inicia servidor web local (http://localhost:8000)
web:
	@lsof -ti :8000 | xargs kill -9 2>/dev/null || true
	@open http://localhost:8000 || true
	@python3 -m http.server 8000

# Atualiza e publica alterações locais no GitHub Pages e na main (mantendo 1 commit por branch)
deploy:
	git add index.html imagens/
	git commit --amend -m "Simulador de Financiamento Imobiliário"
	git push --force origin main
	git switch gh-pages
	git checkout main -- index.html imagens
	git add index.html imagens
	git commit --amend -m "Interface Simulador de Financiamento Imobiliário"
	git push --force origin gh-pages
	git switch main
	@echo "\n✅ Atualização publicada com sucesso no GitHub Pages!"
