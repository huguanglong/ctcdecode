int paddle_beam_decode(THFloatTensor *th_probs,
                                  const char* labels,
                                  int vocab_size,
                                  size_t beam_size,
                                  size_t num_processes,
                                  double cutoff_prob,
                                  size_t cutoff_top_n,
                                  size_t blank_id,
                                  THIntTensor *th_output,
                                  THIntTensor *th_timesteps,
                                  THIntTensor *th_scores,
                                  THIntTensor *th_seq_length);

int paddle_beam_decode_lm(THFloatTensor *th_probs,
                                  const char* labels,
                                  int vocab_size,
                                  size_t beam_size,
                                  size_t num_processes,
                                  double cutoff_prob,
                                  size_t cutoff_top_n,
                                  size_t blank_id,
                                  void *scorer,
                                  THIntTensor *th_output,
                                  THIntTensor *th_timesteps,
                                  THIntTensor *th_scores,
                                  THIntTensor *th_seq_length);

void* paddle_get_scorer(double alpha,
                 double beta,
                 const char* lm_path,
                 const char* labels,
                 int vocab_size);

int is_character_based(void *scorer);
size_t get_max_order(void *scorer);
size_t get_dict_size(void *scorer);
void reset_params(void *scorer, double alpha, double beta);