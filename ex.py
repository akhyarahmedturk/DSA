import faiss
import numpy as np

# Step 1: Define parameters
d = 5   # Vector dimension (small for simplicity)
nb = 5  # Number of database vectors
nq = 3  # Number of query vectors
k = 4   # Number of nearest neighbors to retrieve

# Step 2: Create a random database of vectors
np.random.seed(45)  # For reproducibility
xb = np.random.random((nb, d)).astype('float32')  # Database vectors

# Print generated database vectors
print("\nDatabase vectors (xb):")
print(xb)

# Step 3: Create and add vectors to the Faiss index
index = faiss.IndexFlatL2(d)  # L2 (Euclidean) distance index
index.add(xb)  # Add database vectors
print(f"\nTotal vectors in index: {index.ntotal}")  # Should print '5'

# Step 4: Create random query vectors
xq = np.random.random((nq, d)).astype('float32')  # Query vectors

# Print generated query vectors
print("\nQuery vectors (xq):")
print(xq)

# Step 5: Perform the nearest-neighbor search
D, I = index.search(xq, k)  # Returns distances (D) and indices (I)

# Print search results
print("\nIndices of nearest neighbors:")
print(I)

print("\nDistances to nearest neighbors:")
print(D)
