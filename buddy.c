#include<stdio.h>
#include<string.h>
#include<math.h>
#define len 8192

int main()
{
    //处理输入；
    int n=0,q=0;
    if (scanf("%d %d",&n,&q) != 2) return 1;

    char step[q];
    int id[q],m[q];
    memset(id,0,sizeof(id));
    memset(m,0,sizeof(m));

    // 读取所有 Q/A 操作
    for (int i = 0; i < q; i++) {
        scanf(" %c", &step[i]);
        if (step[i] == 'A') {
            scanf("%d %d", &id[i], &m[i]);
        }
    }

    int memory=1;
    int arr[len];
    int buddy[len];
    memset(arr,0,sizeof(arr));
    memset(buddy,0,sizeof(buddy));
    arr[0]=0;
    buddy[0]=n;



    for (int i=0;i<q;i++)
    {
        // ------------------ Q (查询) 操作 ------------------
        if (step[i] == 'Q') {
            printf("%d\n", memory);
            for (int j = 0; j < memory; j++) {
                printf("%d ", arr[j]);
            }
            printf("\n");
            continue;
        }

        // ------------------ A (分配) 操作 ------------------
        int k = (int)ceil(log2(m[i])); // 计算所需指数 k
        int flag = 0; // flag 用于标记是否分配成功

        // 外层 while 循环：处理分裂后需要重新查找的情况
        while (!flag) {

            // --- 1. 查找恰好大小的空闲块 (buddy[j] == k) ---
            int found_exact_index = -1;
            for (int j = 0; j < memory; j++) {
                if (arr[j] == 0 && buddy[j] == k) {
                    found_exact_index = j;
                    break;
                }
            }

            if (found_exact_index != -1) {
                // 分配成功
                arr[found_exact_index] = id[i];
                flag = 1;
                break;
            }


            int found_larger_index = -1;
            for (int j = 0; j < memory; j++) {
                if (arr[j] == 0 && buddy[j] > k) {
                    found_larger_index = j;
                    break;
                }
            }

            if (found_larger_index != -1) {
                // --- 3. 分裂操作 ---
                int j = found_larger_index; // j 作为分裂点的索引

                // 检查溢出
                if (memory + 1 > len) break;


                for (int move_idx = memory - 1; move_idx > j; move_idx--) {
                    buddy[move_idx + 1] = buddy[move_idx];
                    arr[move_idx + 1] = arr[move_idx];
                }


                buddy[j]--;
                arr[j + 1] = 0;
                buddy[j + 1] = buddy[j];
                memory++;


            } else {
                break;
            }
        }

    }

    return 0;
}