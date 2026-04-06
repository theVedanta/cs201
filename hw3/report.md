# CS 201 - Homework 3 Report

**Topic:** Efficient Search and Retrieval for Movies and Actors

## Student Information

- **Name:** _[Your Name]_
- **Email:** _[Your Email]_
- **Course Section:** Spring 2026 CS 201
- **Homework #:** 3

---

## Objective

Select an efficient data structure and algorithm to support fast search and retrieval of:

1. all actors in a given movie, or
2. all movies for a given actor.

---

## Data Structure and Algorithm Choice

I used two hash-table-based maps from the C++ standard library (`std::unordered_map`):

- **movieToActors**: `movie name -> list of actors`
- **actorToMovies**: `actor name -> list of movies`

### Rationale

This is a bidirectional relationship (movie ↔ actor), so storing only one direction would make the other query type slow.  
Using two hash maps allows direct lookup for both query types in average constant time.

---

## Program Behavior

For each query in `query.txt`:

- If query matches a movie name, print all actors in that movie (one per line).
- Else if query matches an actor name, print all movies for that actor (one per line).
- Otherwise print **Not Found**.

The program also measures:

1. time to build the data structure from DB file,
2. time to process all queries,
3. total time.

---

## Performance Results

| DB File       | # of records | Time taken to create data structure | Time taken to search | Total time taken |
| ------------- | -----------: | ----------------------------------: | -------------------: | ---------------: |
| `dbfile1.txt` |          442 |                            1.998 ms |             0.173 ms |         2.171 ms |
| `dbfile2.txt` |         7065 |                           39.048 ms |             0.203 ms |        39.251 ms |
| `dbfile3.txt` |        14129 |                           77.515 ms |             0.221 ms |        77.736 ms |

---

## Complexity Analysis

Let:

- `R` = number of movie records (lines),
- `E` = total movie-actor pairs across the DB,
- `Q` = number of queries.

### Build Phase

- Parsing + insertion into both hash maps: **O(E)** average-case.

### Search/Retrieval Phase

- Hash lookup for movie and/or actor: **O(1)** average-case per query.
- Output cost depends on result size:
  - movie query: `O(number of actors in that movie)`
  - actor query: `O(number of movies for that actor)`

So practical query complexity is **O(1 + k)** average, where `k` is the number of lines printed.

---

## Comparison and Explanation of Results

- **Creation time increases significantly** from `dbfile1` to `dbfile3` because more records and associations must be parsed and inserted.
- **Search time stays nearly constant** across all DB sizes because hash-table lookup is average O(1), and the query file size is the same.
- This confirms that the selected structure is efficient for large datasets when fast lookup is required.

---

## Conclusion

The chosen two-map hash-table design provides efficient bidirectional retrieval and strong search performance.  
Measured results show scalable build behavior and near-constant-time query processing, which satisfies the homework objective of selecting an efficient data structure and algorithm.
