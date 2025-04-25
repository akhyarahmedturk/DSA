import sys
print("Python version:", sys.version)
print("Python executable:", sys.executable)
print("sys.path:", sys.path)
import codeforces_api
# Replace with the actual contest ID
contest_id = 605233

# Create a Codeforces API client
api = codeforces_api.CodeforcesAPI()

# Get the standings
try:
    standings = api.contest_standings(contest_id, 1)
    print(standings)
except Exception as e:
    print(f"Error: {e}")