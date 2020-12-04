<template>
    <v-app>
        <v-main class="content">
            <MSCRenderer/>
        </v-main>
    </v-app>
</template>

<script>
import MSCRenderer from './views/MSCRenderer';

export default {
  name: 'App',

  components: {
    MSCRenderer,
  },

  data: () => ({
    //
  }),
};
</script>

<style lang="scss">
.content {
    display: flex;
    align-items: center;
    justify-content: center;
}
</style>