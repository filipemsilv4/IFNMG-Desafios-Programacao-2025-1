import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt() // Número de casos de teste

    repeat(t) {
        val n = scanner.nextInt() // Valor a ser pago

        val result = when (n) {
            1, 2, 4 -> n // Para 1, 2 e 4, ela precisa de n moedas de 1 burle
            3, 5 -> 0 // Para 3 e 5, ela não precisa de moedas de 1 burle (pode usar 3 ou 5)
            6 -> 0 // Para 6, pode usar 2 moedas de 3
            7 -> 1 // Para 7, pode usar 1 moeda de 1 e 2 moedas de 3 (1 + 3 + 3)
            else -> 0 // Para n > 7, sempre é possível usar apenas moedas de 3 e 5
        }
        println(result)
    }
    scanner.close()
}