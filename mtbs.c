#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MOVIES 10
#define MAX_USERS 10
#define MAX_BOOKINGS 10

// Define structures for movie, user, and booking
typedef struct {
    int id;
    char title[100];
    char genre[100];
    int duration;
    float rating;
} Movie;

typedef struct {
    int id;
    char name[100];
    char email[100];
    char phone[20];
} User;

typedef struct {
    int id;
    int movie_id;
    int user_id;
    int num_tickets;
} Booking;

// Declare global arrays to store movies, users, and bookings
Movie movies[MAX_MOVIES];
int num_movies = 0;

User users[MAX_USERS];
int num_users = 0;

Booking bookings[MAX_BOOKINGS];
int num_bookings = 0;

// Function declarations
void show_movies();
void register_user();
void book_ticket();
void payment_options();
void view_bookings();
void view_bookings_by_user();

int main() {
    int choice;
    while (1) {
        printf("\nWelcome to the Movie Ticket Booking System\n");
        printf("1. Show available movies\n");
        printf("2. Register user\n");
        printf("3. Book ticket\n");
        printf("4. View all bookings\n");
        printf("5. View bookings by user\n");
        printf("6. Payment options\n");
        printf("7. Exit\n");
        printf("8. Add movie\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        switch (choice) {
            case 1:
                show_movies();
                break;
            case 2:
                register_user();
                break;
            case 3:
                book_ticket();
                break;
            case 4:
                view_bookings();
                break;
            case 5:
                view_bookings_by_user();
                break;
            case 6:
                payment_options();
                break;
            case 7:
                printf("Thank you for using the Movie Ticket Booking System.\n");
                exit(0);
            case 8:
                add_movie();
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void show_movies() {
    if (num_movies == 0) {
        printf("No movies available.\n");
        return;
    }
    printf("Available movies:\n");
    printf("ID  Title  Genre  Duration(min)  Rating\n");
    for (int i = 0; i < num_movies; i++) {
        printf("%d  %s  %s  %d  %.1f\n", movies[i].id, movies[i].title, movies[i].genre );
    }
}

void register_user() {
    if (num_users == MAX_USERS) {
        printf("Maximum number of users reached.\n");
        return;
    }
    User user;
    printf("Enter user name: ");
    scanf("%s", user.name);
    printf("Enter user email: ");
    scanf("%s", user.email);
    printf("Enter user phone: ");
    scanf("%s", user.phone);
    user.id = num_users + 1;
    users[num_users] = user;
    num_users++;
    printf("User registered successfully. User ID is %d\n", user.id);
}

void book_ticket() {
    if (num_movies == 0) {
        printf("No movies available for booking.\n");
        return;
    }
    if (num_users == 0) {
        printf("No users registered for booking.\n");
        return;
    }
    if (num_bookings == MAX_BOOKINGS) {
        printf("Maximum number of bookings reached.\n");
        return;
    }
    Booking booking;
    int movie_id, user_id, num_tickets;
    printf("Enter movie ID: ");
    scanf("%d", &movie_id);
    printf("Enter user ID: ");
    scanf("%d", &user_id);
    printf("Enter number of tickets: ");
    scanf("%d", &num_tickets);
    for (int i = 0; i < num_movies; i++) {
        if (movies[i].id == movie_id) {
            booking.movie_id = movie_id;
            break;
        }
        if (i == num_movies - 1) {
            printf("Invalid movie ID.\n");
            return;
        }
    }
    for (int i = 0; i < num_users; i++) {
        if (users[i].id == user_id) {
            booking.user_id = user_id;
            break;
        }
        if (i == num_users - 1) {
            printf("Invalid user ID.\n");
            return;
        }
    }
    booking.id = num_bookings + 1;
    booking.num_tickets = num_tickets;
    bookings[num_bookings] = booking;
    num_bookings++;
    printf("Ticket booked successfully. Booking ID is %d\n", booking.id);
}

void payment_options() {
    int booking_id, choice;
    printf("Enter booking ID: ");
    scanf("%d", &booking_id);
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].id == booking_id) {
            printf("Booking details:\n");
            printf("Movie: %s\n", movies[bookings[i].movie_id - 1].title);
            printf("User: %s\n", users[bookings[i].user_id - 1].name);
            printf("Number of tickets: %d\n", bookings[i].num_tickets);
            printf("Amount due: %.2f\n", bookings[i].num_tickets * 10.0);
            printf("Payment options:\n");
            printf("1. Credit card\n");
            printf("2. Debit card\n");
            printf("3. Net banking\n");
            printf("Enter your choice: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Credit card payment successful.\n");
                    break;
                case 2:
                    printf("Debit card payment successful.\n");
                    break;
                case 3:
                    printf("Net banking payment successful.\n");
                    break;
                default:
                    printf("Invalid choice.\n");
            }
            return;
        }
        if (i == num_bookings - 1) {
            printf("Invalid booking ID.\n");
            return;
        }
    }
}

void view_bookings() {
    if (num_bookings == 0) {
        printf("No bookings found.\n");
        return;
    }
    printf("All bookings:\n");
    printf("ID  Movie  User  Tickets\n");
    for (int i = 0; i < num_bookings; i++) {
        printf("%d  %s  %s  %d\n", bookings[i].id, movies[bookings[i].movie_id - 1].title, users[bookings[i].user_id - 1].name, bookings[i].num_tickets);
    }
}
void add_movie() {
    if (num_movies == MAX_MOVIES) {
        printf("Maximum number of movies reached.\n");
        return;
    }
    Movie movie;
    printf("Enter movie title: ");
    scanf("%s", movie.title);
    printf("Enter movie genre: ");
    scanf("%s", movie.genre);
    movie.id = num_movies + 1;
    movies[num_movies] = movie;
    num_movies++;
    printf("Movie added successfully. Movie ID is %d\n", movie.id);
}


void view_bookings_by_user() {
    if (num_bookings == 0) {
        printf("No bookings found.\n");
        return;
    }
    int user_id;
    printf("Enter user ID: ");
    scanf("%d", &user_id);
    printf("Bookings for user %d:\n", user_id);
    printf("ID  Movie  Tickets\n");
    for (int i = 0; i < num_bookings; i++) {
        if (bookings[i].user_id == user_id) {
            printf("%d  %s  %d\n", bookings[i].id, movies[bookings[i].movie_id - 1].title, bookings[i].num_tickets);
        }
    }
}


