map<ll, ll> mp;
for(ll i = 0; i < n; i ++){
	ll l = k[i] - h[i] + 1;
	ll r = k[i];
	mp[r] --;
	mp[l] ++;
}
ll pre = 0;
for(auto &it: mp){
	it.second += pre;
	pre = it.second;
}
vector<vector<ll>> segments;
ll st = -1;
for(auto &it: mp){
	if(st != -1 and it.second == 0){
		segments.push_back({st, it.first});
		st = -1;
	}
	else if(st == -1 and it.second == 0){
		segments.push_back({it.first, it.first});
	}
	else if(st == -1) st = it.first;
}
print(segments);
print('\n');