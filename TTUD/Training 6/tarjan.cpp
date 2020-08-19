void tarjan(int u,int p){//u la dinh dang xet, v la dinh truoc no
    low[u]=num[u]=++Time;
    for (int v:a[u]){
        if (v!=p){
            if(num[v]!=-1){//đã xét khi num = -1 cạnh u v sẽ là cạnh ngược và chắc chắn thuộc 1 chu trình, nếu khác -1 chứng tỏ chưa duyệt qua
                    low[u]=min(low[u],num[v]);//low đỉnh cha cập nhật bằng num đỉnh con để thõa mãn low là chỉ số đỉnh nhỏ nhất cạnh ngược đến được
            }
            else {//nếu đỉnh v chưa xét qua, cạnh u v là cạnh xuôi, dfs tiếp tục theo cạnh xuôi
                tarjan(v,u);
                low[u]=min(low[u],low[v]);//lan truyền low nếu có bất kì thằng con cháu nào thuộc 1 cạnh ngược
                if (low[v]>=num[v]) {//uv la cầu
                    isbridge[u][v] = true;
                };
            }
        }
    }
}
