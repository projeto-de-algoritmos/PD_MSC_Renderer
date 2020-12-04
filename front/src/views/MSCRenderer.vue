<template>
    <v-container class="d-flex flex-column align-center">
        <v-text-field
            v-model="sequencia"
            label="Sequência">

        </v-text-field>
        

        <div>
            <div>
                <h2 class="title">Tamanho da maior subsequência: {{ maiorSubSequencia }} </h2> 
            </div>
            <div>
                <h2 class="title">Subsequência: {{ solution }} </h2>
            </div>
        </div>
        
    </v-container>
</template>

<script>
export default {
    data: () => ({
        sequencia: "8,9,1",
        solution: []
    }),
    computed: {
        maiorSubSequencia() {
            return this.calculaMaiorSubsequencia(this.sequencia).max
        },
    },
    methods: {
        formatSequencia(sequencia) {
            if (sequencia == "") return 0;

            sequencia = sequencia.replace(/\s/g, "")
            if (typeof sequencia === "string")
                sequencia = sequencia.split(",")

            return sequencia
        },
        calculaMaiorSubsequencia(sequencia) {
            sequencia = this.formatSequencia(sequencia)

            const input_lst = sequencia
            const temp_lst = new Array(sequencia.length)
            const predecessores = new Array(sequencia.length)

            for (let i = 0; i < sequencia.length; i++) {
                temp_lst[i] = 1
                predecessores[i] = 0

                for (let j = 0; j < i; j++) {
                    if (+input_lst[j] < +input_lst[i] && ((1 + +temp_lst[j]) > +temp_lst[i])) {
                        temp_lst[i] = 1 + temp_lst[j]
                        predecessores[i] = j
                    }
                }
            }

            return {
                temp_lst,
                predecessores,
                max: Math.max(...temp_lst)
            }
        },
        obtemSubsequencias({ temp_lst, predecessores, sequencia }) {
            this.solution = []
            sequencia = this.formatSequencia(sequencia)

            let j = 0
            j = temp_lst.findIndex(elem => elem == Math.max(...temp_lst))
            debugger
            this.solution.push(sequencia[j])
            while(j != predecessores[j] ) {
                j = predecessores[j]
                this.solution.push(sequencia[j])
            }

            this.solution = this.solution.reverse().join(", ")
        }
    },
    watch: {
        sequencia: function(val) {
            if (val) {
                this.obtemSubsequencias({...this.calculaMaiorSubsequencia(val), sequencia: val})
            }
        }
    }
}
</script>