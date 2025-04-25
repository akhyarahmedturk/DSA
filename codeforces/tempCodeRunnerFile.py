
# Create a Codeforces API client
api = codeforces_api.CodeforcesAPI()

# Get the standings
try:
    standings = api.contest_standings(contest_id, 1)
    print(standings)
except Exception as e:
    print(f"Error: {e}")