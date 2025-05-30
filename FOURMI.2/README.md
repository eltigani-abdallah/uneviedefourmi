## **🐜 Projet : Une Vie de Fourmi – Cas n°0**

### **🔢 Données du problème**

* ## **Nombre de fourmis : `F = 2`**   **Salles :**

  * **`Sv` (vestibule) – capacité : 2**

  * **`Sd` (dortoir) – capacité : 2**

  * **`S1.S2` – capacité : 1**

### **📊 Schéma de la fourmilière**

        **`S1(2)`**  
       **`/  \`**  
   **`S2(1)    S3(1)`**  
      **`\    /`**  
        **`S4(2)`**

## 

### **🐜 Simulation des étapes**

#### **Étape 1**

## **`f1 - Sv → S1`**  

## **`f2 - Sv → S2`**  

#### **Étape 2**

## **`f1 - S1 → Sd`**  

## **`f2 - S2 → Sd`**  

## 

## 

## **🐜 Projet : Une Vie de Fourmi – Cas n°1**

### **🔢 Données du problème**

* ## **Nombre de fourmis : `F = 5`** 

* **Salles :**  
  * **`Sv` (vestibule) – capacité : 5**

  * **`Sd` (dortoir) – capacité : 5**

  * **`S1. S2`   – capacité :1**

---

### **🔗 Connexions (Tunnels)**

`Sv → S1`    
`S1 → S2`    
`S2 → Sd`

### **📊 Schéma de la fourmilière**

     **Sv(5)**  
        **|**  
     **S1(1)**  
        **|**  
     **S2(1)**  
        **|**  
      **Sd(5)**

### 🐜 **Simulation des étapes**

#### **Étape 1**

`f1 - Sv → S1`

#### **Étape 2**

`f1 - S1 → S2`    
`f2 - Sv → S1`

#### 

#### **Étape 3**

`f1 - S2 → Sd`    
`f2 - S1 → S2`    
`f3 - Sv → S1`

#### 

#### **Étape 4**

`f2 - S2 → Sd`    
`f3 - S1 → S2`    
`f4 - Sv → S1`

#### 

#### **Étape 5**

`f3 - S2 → Sd`    
`f4 - S1 → S2`    
`f5 - Sv → S1`

#### 

### **Étape 6**

`f5 - S1 → S2`  
`f4 - S2 → Sd`  

#### 

#### **Étape 7**

#### `f5 - S2 → Sd`

## 

## 

## **🐜 Projet : Une Vie de Fourmi – Cas n°2**

* ### **🔢 Données du problème**

* ## **Nombre de fourmis : `F = 5`** 

* **Salles :**

  * **`Sv` (vestibule) – capacité : 5**

  * **`Sd` (dortoir) – capacité : 5**

  * **`S1. S2`   – capacité : 1**

---

### **🔗 Connexions (Tunnels)**

* **Sv → S1**

* **S1 → S2**

* **S2 → Sd**

* **Sd → Sv (cycle complet)**

---

### **📊 Schéma de la fourmilière**

  **`Sv(5)  ─────► Sd (5)`**  
    **`|             |`**  
      
   **`S1(1)  ───`    S2 (1)**  
            
---

### 🐜 **Simulation des étapes**

### **Variante 1**

**Étape 1**  
`f4 - Sv → Sd`  
`f5 - Sv → Sd`  
`f1 - Sv → Sd`    
`f2 - Sv → Sd`  
`f3 - Sv → Sd`

## 

### **Variante 2**

#### **Étape 1**

`f1 - Sv → Sd`   
`f2 - Sv → S1` 

#### **Étape 2**

`f3 - Sv → Sd`   
`f2 - S1 → S2` 

### **Étape 3**

`f2 - S2 → Sd`    
`f4 - Sv → Sd`

### **Étape 4** 

`f5 - Sv → Sd`

## **🐜 Projet : Une Vie de Fourmi – Cas n°3**

---

##  **Projet : Une Vie de Fourmi – Cas n°2**

* ### **🔢 Données du problème**

* ## **Nombre de fourmis : `F = 5`** 

* **Salles :**

  * **`Sv` (vestibule) – capacité : 5**

  * **`Sd` (dortoir) – capacité : 5**

  * **`S1, S2, S3, S4`   – capacité : 1**  
* 

---

### **🔗 Connexions (Tunnels)**

`Sv → S1`    
`S1 → S2`    
`S1 → S4`    
`S2 → S3`    
`S4 → Sd`

---

### **📊 Schéma simplifié de la fourmilière**

        **`Sv(5)`**  
         **`|`**  
        **`S1(1)`**  
       **`/  \`**  
   **`S2(1)    S4(1)`**  
     **`|      |`**  
   **`S3(1)    Sd(1)`**

---

### **🐜 Simulation des étapes**

#### **Étape 1**

`f1 - Sv → S1`  

#### **Étape 2**

`f1 - S1 → S4`    
`f2 - Sv → S1`  

#### **Étape 3**

`f1 - S4 → Sd`    
`f2 - S1 → S2`    
`f3 - Sv → S1`

#### **`Étape 4`**

`f2 - S2 → S3`    
`f3 - S1 → S4`    
`f4 - Sv → S1`

#### **`Étape 5`**

`f3 - S4 → Sd`    
`f4 - S1 → S2`    
`f5 - Sv → S1`

#### **`Étape 6`**

`f4 - S2 → S3`    
`f5 - S1 → S4`

#### **`Étape 7`**

`f5 - S4 → Sd`

## 

## **🐜 Projet : Une Vie de Fourmi – Cas n°4**

### **🔢 Données du problème**

* **Nombre de fourmis : `F = 10`**  
* **Salles :**  
  * **`Sv` (vestibule) – capacité : 10**

  * **`Sd` (dortoir) – capacité : 10**

  * **`S1` – capacité : 2**

  * **`S2`, `S3`, `S5`, `S6` – capacité : 1**

  * **`S4` – capacité : 2**

### **🔗 Connexions (Tunnels)**

`Sv → S1`  
`S1 → S2`  
`S1 → S3`  
`S2 → S4`  
`S3 → S4`  
`S4 → S5`  
`S4 → S6`  
`S5 → Sd`  
`S6 → Sd`

### **📊 Schéma de la fourmilière**

        **`Sv(10)`**  
        **`|`**  
        **`S1(2)`**  
       **`/  \`**  
  **`S2(1)    S3(1)`**  
      **`\    /`**  
       **`S4(2)`**  
      **`/    \`**  
  **`S5(1)      S6(1)`**  
      **`\    /`**  
        **`Sd(10)`**

---

---

### **📅 Résultat – Déplacement par étapes**

| Étape | Actions effectuées |
| ----- | ----- |
| E1 | F1, F2 → Sv → S1 |
| E2 | F1 → S1 → S2 F2 → S1 → S3 F3, F4 → Sv → S1 |
| E3 | F1 → S2 → S4 F2 → S3 → S4 F3 → S1 → S2 F4 → S1 → S3 F5, F6 → Sv → S1 |
| E4 | F1 → S4 → S5 F2 → S4 → S6 F3 → S2 → S4 F4 → S3 → S4 F5 → S1 → S2 F6 → S1 → S3 F7, F8 → Sv → S1 |
| E5 | F1 → S5 → Sd F2 → S6 → Sd F3 → S4 → S5 F4 → S4 → S6 F5 → S2 → S4 F6 → S3 → S4 F7 → S1 → S2 F8 → S1 → S3 F9, F10 → Sv → S1 |
| E6 | F3 → S5 → Sd F4 → S6 → Sd F5 → S4 → S5 F6 → S4 → S6 F7 → S2 → S4 F8 → S3 → S4 F9 → S1 → S2 F10 → S1 → S3 |
| E7 | F5 → S5 → Sd F6 → S6 → Sd F7 → S4 → S5 F8 → S4 → S6 F9 → S2 → S4 F10 → S3 → S4 |
| E8 | F7 → S5 → Sd F8 → S6 → Sd F9 → S4 → S5 F10 → S4 → S6 |
| E9 | F9 → S5 → Sd F10 → S6 → Sd |

## 

##  **Projet : Une Vie de Fourmi – Cas n°5**

### **🔢 Données du problème**

* Nombre de fourmis : `F = 50`  
* Salles :  
  * `Sv` (vestibule) – capacité : 50  
  * `Sd` (dortoir) – capacité :50  
  * `S1` – capacité :8  
  * `S2`, `S6` – capacité : 4  
  * `S3, S5, S7`   – capacité : **2**  
  * `S8`  – capacité :5  
  * `S4`   – capacité : **4**  
  * `S9, S10, S11,S12`  – capacité : **1**  
  * `S14` – capacité : **2**  
  * `S13`  capacité : **4**

                 **    Sv(50)**

                         **|**

                       **S1(8)**

                     **/               \\**

              **S2(4)                 S6(4)**

           **/    \\                          /     \\**

  **S3(2)      S5(2)          S7(2)      S8(5)**

         **\\      /                 /  \\                    /  \\**

          **S4(4)       S9(1)   S10(1)   S11(1)   S12(1)**

                **|               \\   /                     \\   /**

                **|            S14(2)            S13(4)**

                **|                    \\               /**

                **\+-------------\> Sd(50)**

### **🔗 Connexions (Tunnels)**

Sv  → S1    
S1  → S2    
S1  → S6    
S2  → S3    
S2  → S5    
S3  → S4    
S5  → S4    
S4  → Sd    
S6  → S7    
S6  → S8    
S7  → S9    
S7  → S10    
S9  → S14    
S10 → S14    
S14 → Sd    
S8  → S11    
S8  →   S12    
S11 →   S13    
S12 →   S13    
S13 →   Sd

### **📊 Schéma de la fourmilière**

### **Étape 1**

`f1  - Sv → S1`    
`f2  - Sv → S1`    
`f3  - Sv → S1`    
`f4  - Sv → S1`    
`f5  - Sv → S1`    
`f6  - Sv → S1`    
`f7  - Sv → S1`    
`f8  - Sv → S1`  

---

### **Étape 2**

`f1  - S1 → S2`    
`f2  - S1 → S2`    
`f3  - S1 → S2`    
`f4  - S1 → S2`    
`f5  - S1 → S6`    
`f6  - S1 → S6`    
`f7  - S1 → S6`    
`f8  - S1 → S6`    
`f9  - Sv → S1`    
`f10 - Sv → S1`    
`f11 - Sv → S1`    
`f12 - Sv → S1`    
`f13 - Sv → S1`    
`f14 - Sv → S1`    
`f15 - Sv → S1`    
`f16 - Sv → S1`  

---

### **Étape 3**

`f1  - S2 → S3`    
`f2  - S2 → S3`    
`f3  - S2 → S5`    
`f4  - S2 → S5`    
`f5  - S6 → S7`    
`f6  - S6 → S7`    
`f7  - S6 → S8`    
`f8  - S6 → S8`    
`f9  - S1 → S2`    
`f10 - S1 → S2`    
`f11 - S1 → S2`    
`f12 - S1 → S2`    
`f13 - S1 → S6`    
`f14 - S1 → S6`    
`f15 - S1 → S6`    
`f16 - S1 → S6`    
`f17 - Sv → S1`    
`f18 - Sv → S1`    
`f19 - Sv → S1`    
`f20 - Sv → S1`    
`f21 - Sv → S1`    
`f22 - Sv → S1`    
`f23 - Sv → S1`    
`f24 - Sv → S1`  

---

### **Étape 4**

`f1  - S3 → S4`    
`f2  - S3 → S4`    
`f3  - S5 → S4`    
`f4  - S5 → S4`    
`f5  - S7 → S9`    
`f6  - S7 → S10`    
`f7  - S8 → S11`    
`f8  - S8 → S12`    
`f9  - S2 → S3`    
`f10 - S2 → S3`    
`f11 - S2 → S5`    
`f12 - S2 → S5`    
`f13 - S6 → S7`    
`f14 - S6 → S7`    
`f15 - S6 → S8`    
`f16 - S6 → S8`    
`f17 - S1 → S2`    
`f18 - S1 → S2`    
`f19 - S1 → S2`    
`f20 - S1 → S2`    
`f21 - S1 → S6`    
`f22 - S1 → S6`    
`f23 - S1 → S6`    
`f24 - S1 → S6` 

## **✅ Étape 5**

`f1  - S4 → Sd`    
`f2  - S4 → Sd`    
`f3  - S4 → Sd`    
`f4  - S4 → Sd`    
`f5  - S9 → S14`    
`f6  - S10 → S14`    
`f7  - S11 → S13`    
`f8  - S12 → S13`    
`f9  - S3 → S4`    
`f10 - S3 → S4`    
`f11 - S5 → S4`    
`f12 - S5 → S4`    
`f13 - S7 → S9`    
`f14 - S7 → S10`    
`f15 - S8 → S11`    
`f16 - S8 → S12`    
`f17 - S2 → S3`    
`f18 - S2 → S3`    
`f19 - S2 → S5`    
`f20 - S2 → S5`    
`f21 - S6 → S7`    
`f22 - S6 → S7`    
`f23 - S6 → S8`    
`f24 - S6 → S8`    
`f25 - S1 → S2`    
`f26 - S1 → S2`    
`f27 - S1 → S2`    
`f28 - S1 → S2`    
`f29 - S1 → S6`    
`f30 - S1 → S6`    
`f31 - S1 → S6`    
`f32 - S1 → S6`    
`f33 - Sv → S1`    
`f34 - Sv → S1`    
`f35 - Sv → S1`    
`f36 - Sv → S1`    
`f37 - Sv → S1`    
`f38 - Sv → S1`    
`f39 - Sv → S1`    
`f40 - Sv → S1`  

---

## **✅ Étape 6**

`f5  - S14 → Sd`    
`f6  - S14 → Sd`    
`f7  - S13 → Sd`    
`f8  - S13 → Sd`    
`f9  - S4 → Sd`    
`f10 - S4 → Sd`    
`f11 - S4 → Sd`    
`f12 - S4 → Sd`    
`f13 - S9 → S14`    
`f14 - S10 → S14`    
`f15 - S11 → S13`    
`f16 - S12 → S13`    
`f17 - S3 → S4`    
`f18 - S3 → S4`    
`f19 - S5 → S4`    
`f20 - S5 → S4`    
`f21 - S7 → S9`    
`f22 - S7 → S10`    
`f23 - S8 → S11`    
`f24 - S8 → S12`    
`f25 - S2 → S3`    
`f26 - S2 → S3`    
`f27 - S2 → S5`    
`f28 - S2 → S5`    
`f29 - S6 → S7`    
`f30 - S6 → S7`    
`f31 - S6 → S8`    
`f32 - S6 → S8`    
`f33 - S1 → S2`    
`f34 - S1 → S2`    
`f35 - S1 → S2`    
`f36 - S1 → S2`    
`f37 - S1 → S6`    
`f38 - S1 → S6`    
`f39 - S1 → S6`    
`f40 - S1 → S6`    
`f41 - Sv → S1`    
`f42 - Sv → S1`    
`f43 - Sv → S1`    
`f44 - Sv → S1`    
`f45 - Sv → S1`    
`f46 - Sv → S1`    
`f47 - Sv → S1`    
`f48 - Sv → S1`  

---

### **✅ Étape 7**

`f13 - S14 → Sd`    
`f14 - S14 → Sd`    
`f15 - S13 → Sd`    
`f16 - S13 → Sd`    
`f17 - S4 → Sd`    
`f18 - S4 → Sd`    
`f19 - S4 → Sd`    
`f20 - S4 → Sd`    
`f21 - S9 → S14`    
`f22 - S10 → S14`    
`f23 - S11 → S13`    
`f24 - S12 → S13`    
`f25 - S3 → S4`    
`f26 - S3 → S4`    
`f27 - S5 → S4`    
`f28 - S5 → S4`    
`f29 - S7 → S9`    
`f30 - S7 → S10`    
`f31 - S8 → S11`    
`f32 - S8 → S12`    
`f33 - S2 → S3`    
`f34 - S2 → S3`    
`f35 - S2 → S5`    
`f36 - S2 → S5`    
`f37 - S6 → S7`    
`f38 - S6 → S7`    
`f39 - S6 → S8`    
`f40 - S6 → S8`    
`f41 - S1 → S2`    
`f42 - S1 → S2`    
`f43 - S1 → S2`    
`f44 - S1 → S2`    
`f45 - S1 → S6`    
`f46 - S1 → S6`    
`f47 - S1 → S6`    
`f48 - S1 → S6`    
`f49 - Sv → S1`    
`f50 - Sv → S1`  

---

### **✅ Étape 8**

`f21 - S14 → Sd`    
`f22 - S14 → Sd`    
`f23 - S13 → Sd`    
`f24 - S13 → Sd`    
`f25 - S4 → Sd`    
`f26 - S4 → Sd`    
`f27 - S4 → Sd`    
`f28 - S4 → Sd`    
`f29 - S9 → S14`    
`f30 - S10 → S14`    
`f31 - S11 → S13`    
`f32 - S12 → S13`    
`f33 - S3 → S4`    
`f34 - S3 → S4`    
`f35 - S5 → S4`    
`f36 - S5 → S4`    
`f37 - S7 → S9`    
`f38 - S7 → S10`    
`f39 - S8 → S11`    
`f40 - S8 → S12`    
`f41 - S2 → S3`    
`f42 - S2 → S3`    
`f43 - S2 → S5`    
`f44 - S2 → S5`    
`f45 - S6 → S7`    
`f46 - S6 → S7`    
`f47 - S6 → S8`    
`f48 - S6 → S8`    
`f49 - S1 → S2`    
`f50 - S1 → S2`  

---

### **✅ Étape 9**

`f29 - S14 → Sd`    
`f30 - S14 → Sd`    
`f31 - S13 → Sd`    
`f32 - S13 → Sd`    
`f33 - S4 → Sd`    
`f34 - S4 → Sd`    
`f35 - S4 → Sd`    
`f36 - S4 → Sd`    
`f37 - S9 → S14`    
`f38 - S10 → S14`    
`f39 - S11 → S13`    
`f40 - S12 → S13`    
`f41 - S3 → S4`    
`f42 - S3 → S4`    
`f43 - S5 → S4`    
`f44 - S5 → S4`    
`f45 - S7 → S9`    
`f46 - S7 → S10`    
`f47 - S8 → S11`    
`f48 - S8 → S12`    
`f49 - S2 → S3`    
`f50 - S2 → S3`  

---

### **✅ Étape 10**

`f37 - S14 → Sd`    
`f38 - S14 → Sd`    
`f39 - S13 → Sd`    
`f40 - S13 → Sd`    
`f41 - S4 → Sd`    
`f42 - S4 → Sd`    
`f43 - S4 → Sd`    
`f44 - S4 → Sd`    
`f45 - S9 → S14`    
`f46 - S10 → S14`    
`f47 - S11 → S13`    
`f48 - S12 → S13`    
`f49 - S3 → S4`    
`f50 - S3 → S4`  

---

### **✅ Étape 11**

`f45 - S14 → Sd`    
`f46 - S14 → Sd`    
`f47 - S13 → Sd`    
`f48 - S13 → Sd`    
`f49 - S4 → Sd`    
`f50 - S4 → Sd`

