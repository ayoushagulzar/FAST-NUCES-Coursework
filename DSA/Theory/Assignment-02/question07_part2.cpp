// A national logistics enterprise processes 5,000,000 parcels globally every day. Each parcel object
// contains a unique, non-negative numeric tracking number (ranging from 0 up to 999,999,999), a
// sender name, a destination city, and a region routing code.
// Develop a C++ program to sort these parcel records under two distinct scenarios. You must write your
// sorting algorithms completely from scratch without using any built-in language sorting features.

// Part 2: Regional Code Consolidation
// Your system must also group parcels by their numeric region routing codes.
// The Constraints: Due to strict memory caps on our edge-computing servers, your sorting algorithm
// cannot exceed O(log n) auxiliary space complexity, eliminating heavy array mirroring. However, it
// must guarantee a predictable worst-case time complexity of O(nlogn) to prevent processing
// bottlenecks, and it must be stable so that if two parcels share the same regional code, their original
// sequence remains perfectly intact.
