# Bank System & Currency Exchange

A feature-rich **C++ console banking application** built to demonstrate Object-Oriented Programming, file-based persistence, authentication, authorization, client management, financial transactions, transfer logging, and currency exchange.

## Project Status

**Core banking functionality is implemented.** The application currently uses local text files as its persistence layer rather than an external SQL database.

## Feature Status

### Implemented — Working

#### Client Management

- **List clients**
- **Add new clients**
- **Update client information**
- **Delete clients**
- **Find clients by account number**
- **Client balance tracking**
- **Total balance calculation**
- **Persistent client storage in `Clients.txt`**

#### Transactions

- **Deposit**
- **Withdraw**
- **Balance updates**
- **Money transfer between accounts**
- **Transfer validation**
- **Transfer history**
- **Transfer log stored in `TransferLog`**

#### User Management

- **User login**
- **User creation**
- **User update**
- **User deletion**
- **User search**
- **User listing**
- **Login register**
- **Role/permission-based access control**
- **Permission checks for protected screens**

#### Currency Exchange

- **Currency listing**
- **Currency search**
- **Currency rate updates**
- **Currency calculator**
- **Conversion through USD as a reference**
- **Persistent currency data in `Currencies.txt`**

#### Application Structure

- Screen-based console UI.
- Reusable classes and utilities.
- File-based data access.
- Object-oriented domain classes.
- Input validation utilities.
- Separate screens for different application operations.

### Partially Implemented / Needs Refinement

- **Security** — Authentication and permissions are implemented, but credentials are stored and compared through local files and should not be treated as production-grade security.
- **Transaction consistency** — Transfers update two client records sequentially; stronger transactional/rollback handling would improve reliability.
- **Input handling** — Validation utilities are present, but additional edge-case handling can be added.
- **Cross-platform support** — The application uses Windows console functions such as `system("cls")` and `system("pause")`.

### Planned — Coming Soon

The following improvements are **not currently implemented** and are planned for future updates:

- Secure password hashing.
- Database-backed persistence.
- Transaction rollback/atomic operations.
- Stronger financial validation.
- Improved cross-platform console support.
- Automated tests.
- More detailed reporting and analytics.
- Additional currency-management capabilities.
- UI and codebase refinements.

## Main Menu

```text
1. Show Clients
2. Add New Client
3. Delete Client
4. Update Client
5. Find Client
6. Transactions
7. Manage Users
8. Login Register
9. Currency Exchange
10. Logout
```

## Transaction Menu

```text
1. Deposit
2. Withdraw
3. Show Total Balances
4. Transfer
5. Transfer Log
6. Main Menu
```

## Architecture

```text
Console Screens
      │
      ▼
Business / Domain Classes
      │
      ├── Client Management
      ├── User Management
      ├── Transactions
      └── Currency Exchange
      │
      ▼
Text File Persistence
```

## Technologies & Concepts

- **C++**
- Object-Oriented Programming
- Inheritance
- Encapsulation
- Classes and enums
- STL containers
- File I/O
- Input validation
- Role-based permissions
- Console application design

## Project Structure

The project is organized around reusable classes such as:

- `clsBankClient`
- `clsUser`
- `clsCurrency`
- `clsMainScreen`
- `clsTransactionsScreen`
- `clsTransferScreen`
- `clsManageUsersScreen`
- `clsCurrencyCalculatorScreen`
- Utility and validation classes

## Getting Started

1. Open the project in **Visual Studio**.
2. Build the C++ project.
3. Run the generated executable.
4. Make sure the required text files are available in the application's working directory.

## Learning Objectives

This project demonstrates:

- Designing a multi-feature C++ console application.
- Applying OOP principles to a larger codebase.
- Managing persistent data using file handling.
- Implementing authentication and authorization.
- Building financial transaction workflows.
- Working with reusable screen and utility classes.

## Roadmap

Future updates will focus on stronger security, database integration, safer transaction handling, additional reporting, and broader platform support.

## Author

**Aseelcoding**
