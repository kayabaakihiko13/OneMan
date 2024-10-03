# Compiler yang digunakan
CXX := clang

# Flags untuk kompilasi
CXXFLAGS := -O3 -fopenmp
# Nama target
TARGET := output.exe

# Sumber file
SOURCES := main.c

# Aturan untuk membuat target executable
$(TARGET): $(SOURCES)
	$(CXX) -o $(TARGET) $(SOURCES) $(CXXFLAGS)

# Aturan untuk membersihkan file objek dan executable
clean:
	rm -f $(TARGET)

# Menggunakan phony targets untuk target yang tidak menghasilkan file
.PHONY: clean