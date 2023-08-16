# Facts
likes = {
    "Rajani": ["mango", "ice_cream"],
    "Suhana": ["banana", "ice_cream"],
    "Samir": ["salad", "chocolate"]
}

# Rules
def friend(X, Y):
    common_likes = [Z for Z in likes[X] if Z in likes[Y]]
    return len(common_likes) > 0

# Test the rules
print(friend("Rajani", "Suhana"))  # Output: True
print(friend("Rajani", "Samir"))   # Output: False
print(friend("Suhana", "Samir"))   # Output: True
