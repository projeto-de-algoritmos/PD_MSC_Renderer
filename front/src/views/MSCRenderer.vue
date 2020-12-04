<template>
    <v-container class="d-flex flex-column align-center justify-center mb-4">
        <v-text-field
            
            class="text-center"
            v-model="sequencia"
            label="Sequência" />        

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
        sequencia: "",
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

            if (!sequencia) return 0;


            const input_lst = sequencia
            const temp_lst = sequencia.map(item => {
                console.log(item)
                return 1
            })
            const predecessores = sequencia.map((item, index) => {
                console.log(item)
                return index
            })

            for (let i = 0; i < sequencia.length; i++) {


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

<style lang="scss">
.v-input {
    width: 100%;

    input {
        text-align: center;
    }
}
</style>