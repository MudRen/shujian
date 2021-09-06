#include <get_place.h>

string *no_kill_list = ({
	"mu ren", "jin ren", "yin ren", "zhong shentong", "zhu cong", "shi ren", "huo du","he shiwo"
});

int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 || ob->query("env/invisibility")
	 || ob->query("no_quest")
	 || member_array(ob->query("id"), no_kill_list) != -1
	 || userp(ob)
	 || ob->query("attitude")=="aggressive"
	 || ob->query("have_master")
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
	 || room->query("cant_hubiao")
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/baituo") == 0
	 || strsrch(room_name, "/d/beijing") == 0
	 || strsrch(room_name, "/d/city") == 0
	 || strsrch(room_name, "/d/dali") == 0
	 || strsrch(room_name, "/d/death") == 0
	 || strsrch(room_name, "/d/fairyland") == 0
	 || strsrch(room_name, "/d/foshan") == 0
	 || strsrch(room_name, "/d/fuzhou") == 0
	 || strsrch(room_name, "/d/group") == 0
	 || strsrch(room_name, "/d/gumu") == 0
	 || strsrch(room_name, "/d/hj") == 0
	 || strsrch(room_name, "/d/hmy") == 0
	 || strsrch(room_name, "/d/hz") == 0
	 || strsrch(room_name, "/d/jiaxing") == 0
	 || strsrch(room_name, "/d/kunlun") == 0
	 || strsrch(room_name, "/d/meizhuang") == 0
	 || strsrch(room_name, "/d/miaojiang") == 0
	 || strsrch(room_name, "/d/mingjiao") == 0
	 || strsrch(room_name, "/d/mr") == 0
	 || strsrch(room_name, "/d/ningbo") == 0
	 || strsrch(room_name, "/d/putian") == 0
	 || strsrch(room_name, "/d/sld") == 0
	 || strsrch(room_name, "/d/suzhou") == 0
	 || strsrch(room_name, "/d/thd") == 0
	 || strsrch(room_name, "/d/tianshan") == 0
	 || strsrch(room_name, "/d/wizard") == 0
	 || strsrch(room_name, "/d/wuguan") == 0
	 || strsrch(room_name, "/d/xiakedao") == 0
	 || strsrch(room_name, "/d/xingxiu") == 0
	 || strsrch(room_name, "/d/zhiye") == 0
         || strsrch(room_name, "/d/xiaoyao") == 0
         || strsrch(room_name, "/d/quanzhen") == 0	
         || strsrch(room_name, "/d/xueshan/caoyuan") == 0
	 || strsrch(room_name, "/d/wudang/houshan") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/huanghe/yyd") == 0 )
	 return 0;
	return 1;
}

int do_accept(string arg)
{
	object ob, cart, biaotou, target, *living;
	object me, *team, maxplayer, place;
	int totalexp=0, maxexp, minexp;
	int i, j, teams;
	string endname, str;
        mixed *local;

        local = localtime(time() * 60);
	me = this_player();
me->start_busy(1+random(2));
	if (arg != "quest") return 0;
//	if ((local[2] < 5 || local[2] > 21) && !wizardp(me)) {
//		command("say ҹ�令�ڣ�ʵ��̫��Σ�գ��ҷ��Ĳ��¡�");
//        	return 1;
//        }
        if (sizeof(filter_array(children(__DIR__"obj/cart"), (: clonep :))) > 6) {
		command("say ���������Ѿ����˽�����֧���ˡ�");
		return 1;
	}

	team = me->query_team();
	if (sizeof(team) < 2 ){
		command("say ����·;Σ�գ�����ô�ٵ��ˣ��ҿɲ����ġ�");
		return 1;
	}
	else if(sizeof(team) > 4){
		command("say ����·;Σ�գ������˶���û�õġ�");
		return 1;
	}
	if ( team[0] != me) {
		command("say ֻ�ж����������������ڡ�");
		return 1;
	}
	for (i=0;i<sizeof(team);i++){
		if (!team[i]){
			command("say ��Ķ�����������⣬���ɢ�������齨��");
			return 1;
		}
		if (team[i]->query_temp("protecting")) {
			command("say �ţ���Ķ�������ô�����̰��֮�ˣ�");
			return 1;
		}

		if( team[i]->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		{
			command("say ���������ڽ���֮�У����ǻ����ȴ����������������˵�ɡ�");
			return 1;
		}
		if (!present(team[i])){
			command("say �ף���ô�����˲�ȫ����"+team[i]->query("name")+"��ôû����");
			return 1;
		}

                if (me == team[i]) continue;
/*
		if (!interactive(team[i]) || query_ip_number(team[i]) == query_ip_number(me)) {
			command("say �㻹�ǽ�"+team[i]->query("name")+"���������˰ɡ�");
		return 1;

		}
*/
	}
	maxexp=minexp=team[0]->query("combat_exp");
	maxplayer=team[0];
	for (i=0;i<sizeof(team);i++){
		if (team[i]->query("combat_exp") < 500000) {
			command("say ����·;Σ�գ��ҿ���λ"+RANK_D->query_respect(me)+"��Ҫһ���ô��");
			return 1;
		}
		if (team[i]->query("balance") < 1000000 && !wizardp(team[i])) {
			command("say ������Σ�յ��£��ҿ�"+team[i]->query("name")+RANK_D->query_respect(team[i])+"û���⳥������");
			return 1;
		}
		if (team[i]->query("job_name") == "���ݻ���" && !wizardp(team[i])){
			command("say һֱ���ں�����ģ��ҿ���λ"+team[i]->query("name")+RANK_D->query_respect(team[i])+"����ȥЪϢƬ�̰ɣ�");
			return 1;
		}
		if (team[i]->query_condition("job_busy") && !wizardp(team[i])){
			command("say һֱ���ں�����ģ��ҿ���λ"+team[i]->query("name")+RANK_D->query_respect(team[i])+"����ȥЪϢƬ�̰ɣ�");
			return 1;
		}
		totalexp = totalexp + team[i]->query("combat_exp");
		if(team[i]->query("combat_exp") > maxexp) {
			maxexp=team[i]->query("combat_exp");
			maxplayer=team[i];
		}
		else if(team[i]->query("combat_exp") < minexp)
			minexp=team[i]->query("combat_exp");
	}
	if( totalexp < 1500000 || (maxexp-minexp) > 5000000 ){
		command("say ����·;Σ�գ��ҿ���λ����������䣬�ƺ��޴�������");
		return 1;
	}

	teams=sizeof(team);

// ѡ����Ŀ��

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if(check(living[j])) {
			target = living[j];
			str = environment(target)->query("short");
			if( str == "��ɮ��"
			 || str == HIR"������"NOR
			 || str == "��շ�ħȦ"
			 || str == HIB"����Ժ"NOR) continue;
			if( get_place(base_name(environment(target)))!="" )
				break;
		}
	}

	place = environment(target);
	if (!place) {
		command("say ��ʱû������Ҫ�ͼ�"+RANK_D->query_respect(team[0])+"����");
		return 1;
	}

	target = new(__DIR__"hbtarget");
	target->move(place);

	for (i=0; i<5; i++)
		target->random_move();

	place = environment(target);

	if (strsrch(file_name(place), "/d/zhiye/") >= 0 
	 || strsrch(file_name(place), "/d/group/") >= 0){
	 	if ( place->query("outdoors"))
			endname =  place->query("outdoors")+place->query("short");
	 	else if ( place->query("indoors"))
			endname =  place->query("indoors")+place->query("short");
		else endname =  place->query("short");
	}
	else endname = get_place(base_name(place))+place->query("short");

//	endname = get_place(base_name(place))+place->query("short");

	command("say �뻤����һ��������"+endname+CYN"��"+target->name()+"���С�");

	log_file("job/hubiao",
		sprintf("%8s%-10s������������õ��������񣬹�%1s��������Ҫ�ʹ�"HIR"%s"NOR"��\n",
			me->name(1),
			"("+capitalize(me->query("id"))+")",
			chinese_number(sizeof(team)),
			endname
		), me
	);

	message_vision("$N������Ѻ��"+chinese_number(sizeof(team)*50)+"���ƽ𽻸����ھ֡�\n", me);

	say("һ���ڳ�����Ժʻ����\n");

	cart=new(__DIR__"obj/cart");
	cart->set_temp("teams", teams);

	if(teams > 3)
		cart->set_temp("team4",team[3]);
	if(teams > 2)
		cart->set_temp("team3",team[2]);
	if(teams > 1)
		cart->set_temp("team2",team[1]);
	if(teams > 0)
		cart->set_temp("team1",team[0]);

	cart->set("long", cart->query("long")+"��֧�����ɸ����ھ���ʦ"+me->query("name")+"�����͵�"+HIR+endname+HIY+target->name()+NOR"���ϵġ�\n");
	cart->set("teamhead", me->query("name"));
	cart->set("arrive", endname);
	cart->set("target", target);

	for(i=0; i < sizeof(team); i++) {
		team[i]->set_temp("protecting",cart);
		team[i]->apply_condition("job_busy", 45);
		team[i]->add("balance", -500000);
		team[i]->set_temp("death", team[i]->query("death_count"));
		//GIFT_D->check_count(team[i],this_object(),"����");
	}

	cart->move(environment());

	biaotou = new(__DIR__"biaotou");
	biaotou->set_temp("level", maxplayer->query("max_pot") - 100);
	biaotou->set_temp("qi", maxplayer->query("max_qi"));
	biaotou->set_temp("jing", maxplayer->query("max_jing"));
	biaotou->set_temp("neili", maxplayer->query("max_neili"));
	biaotou->set_temp("jingli", maxplayer->query("max_jingli"));
	biaotou->move(environment());
	biaotou->set_temp("protecting",cart);
	biaotou->set("combat_exp", maxplayer->query("combat_exp"));

	ob=new("/clone/money/silver");
	ob->set_amount(1000+random(100));
	ob->set("name","����");
	ob->move(cart);

	ob=new(__DIR__"biaoshi");
	ob->move(environment());
	ob->set_temp("protecting", cart);

	ob=new(__DIR__"biaoshi");
	ob->move(environment());
	ob->set_temp("protecting", cart);

	me->set_temp("hubiao/where", base_name(environment(target))); //����Ŀ��
	me->set_temp("hubiao/biao_time", uptime());
	me->set_temp("hubiao/target", target);
	return 1;
}

int test_dart()
{
	object ob = this_player();
 
  if ( ob->query_condition("hb_job_busy")){
               command("say "+RANK_D->query_respect(ob)+"�ϴλ��������ˣ���������Ϣһ����˵�ɡ�");
ob->add_busy(1+ random(2));
               return 1;
        }


	if (ob->query_condition("job_busy")
	 || ob->query_temp("protecting")
	 || random(100) > 80) {
ob->add_busy(1+ random(2));
                command("say ����û������Ҫ�ͼ�"+RANK_D->query_respect(ob)+"����");
		return 1;
	}



	command("say ���Ǹ����ھ��������У��б�������Ҫ�͵�������");
	do_accept("quest");
	return 1;
}
