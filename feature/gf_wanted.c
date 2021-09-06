// gf_wanted.c For GuanFu jobs.
// By snowman@SJ 10/06/2000

#include <ansi.h>
#include <guanfu.h>

mapping wanted;
mapping query_wanted() { return wanted; }
string *query_wanted_list() { return keys(wanted); }
int query_wanted_size() { return sizeof(wanted); }
string wanted_list = "\nĿǰ�ΰ����ã��ٸ����κ�ͨ������������\n\n";
private int do_wanted(object ob, mixed info);

int clear_wanted_list()
{
	wanted = ([]);
	wanted_list = "\nĿǰ�ΰ����ã��ٸ����κ�ͨ������������\n\n";
	return 1;
}

string look_wanted(){	return wanted_list; }

void modify_list(int search)
{
	string *key, str = "\n";
      	int i, size;
      	object *obs;
		
	if( search ){
		clear_wanted_list();
		obs = filter_array(children(WANTED_NPC), (: clonep :));
		i = sizeof(obs);
		if( i && i > 0 ){
			while(i--){
				if( !environment(obs[i]) )
					destruct(obs[i]);
				else do_wanted(obs[i], obs[i]->query("gf_wanted_info"));
			}
		}
	}
	
      	key = query_wanted_list();
      	size = query_wanted_size();
      	if ( !size ){
      		wanted_list = "\nĿǰ�ΰ����ã��ٸ����κ�ͨ������������\n\n";
		return;
	}
	
      	for( i = 0; i < size; i++ ){
                str += sprintf("    %-30s���书%-8s���ͽ�%s\n", wanted[key[i]]["name"]+"("+capitalize(key[i])+")", wanted[key[i]]["level"], MONEY_D->money_str(wanted[key[i]]["reward"]*10));
      	}
      	str += "\n�Ұ����� jie <ͨ����id> �ĸ�ʽ��\n";
    	wanted_list = "������ͨ�������ﷸ��"+str+"\n\n";
    	return;
}

void del_wanted(string id)
{
	map_delete(wanted, id);
	modify_list(0);
}

void do_give_reward(string id, mapping target, object me, int dead)
{
	int exp, pot, i;
	
	if( !stringp(id) || !mapp(target) || !objectp(me) ) return;
	if( id == target["id"] ) {
		exp = target["reward"];
		if ( target["exp"] ) {
			i = me->query("combat_exp", 1)/ target["exp"];
			if ( i > 3 ) i = 4;
			if ( i < 1 ) i = 1;
		}
		else i = 1;
		exp /= i;
		if ( dead && target["action"] != "�͵ظ�ɱ" ){
			exp /= 2+random(3);
			pot = exp/4;
		}
		
		else {
			me->add("job_time/�ٸ�", 1);
			pot = exp/3;
			tell_object(me, "��Ϊ�ٸ�Ч���Ĵ��������ˣ�Ŀǰ�Ѵﵽ"+chinese_number(me->query("job_time/�ٸ�"))+"�Ρ�\n");
		}
		
		me->add("combat_exp", exp);
		me->add("potential", pot);
		if( me->query("potential") > me->query("max_pot") * 3 )
			me->set("potential", me->query("max_pot")); 
		me->add("shen", exp * 2);
                me->add("balance", exp * 10);
		me->start_busy(3);
                tell_object(me, "\n��õ����ͽ�"+MONEY_D->money_str(exp*10)+"��"+chinese_number(pot)+"��Ǳ�ܺ�"+chinese_number(exp)+"�㾭�飡\n");
		tell_object(me, "����ͽ��ȥǮׯ��ȡ��\n");
		me->set("job_name","�ٸ�����");
		log_file("job/guanfu", sprintf("%-18s ͨ�����񣬵� %4d Exp��%4d Pot��ĿǰExp��%d\n",
          		me->name()+"("+me->query("id")+")", exp, pot, me->query("combat_exp")),me);
		del_wanted(id);	
	}
	else tell_object(me, "Error! ��֪ͨ��ʦ��\n");
}

string *act = ({ "ɱ������", "͵����ƭ", "��·����", "����ɱ��", "ɱ�˾ܲ�", "����Ǳ��", "Խ��Ǳ��", "ı�ƺ���" });

private int do_wanted(object ob, mixed info)
{	
	string id, place;
	int exp;
	
        if (!ob->is_character() ) return 0;
        id = ob->query("id");
        if ( mapp(wanted[id]) ) return 0;
        	
        if( !mapp(info) ){
                exp = ob->query("combat_exp") / 2000;
        	if ( exp > 1800 ) exp = 1800;
                exp = exp/4 + random(exp*3/4);
        	if (!stringp(place = base_name(environment(ob))) )
        		place = "��ԭ����";
        	else place = TASK_D->get_regions(base_name(environment(ob)))+environment(ob)->query("short");
        	info = ([
        		"name" 	: ob->name(1),
        		"reward": exp,
        		"exp"   : ob->query("combat_exp"),
        		"gender": ob->query("gender"),
        		"level"	: "/cmds/std/look"->gettof(ob, 2),
        		"age"	: ob->query("age"),
        		"act"	: act[random(sizeof(act))],
        		"action": random(2)?"�͵ظ�ɱ":"���ù鰸",
        		"place" : place,
        		"base"	: ob,
        		"wenshu": 2+random(5),
        	]);
        }
	ob->set("gf_wanted_info", info);
	
        if( wanted[id] = info ) return 1;
	else return 0;
}

int do_jie(string arg)
{
        object me, wenshu;
        mapping target;
        int i, exp;
	string str;
	
	me = this_player();
	if (me->is_busy() || me->is_fighting() ) 
		return notify_fail("����æ������˵�ɡ�\n");
	
	me->start_busy(2);
	
        if (!arg)
        	return notify_fail("��ҿ�����һƬ��Ƭ���˿���\n");

	if ( !query_wanted_size() ) 
		return notify_fail("Ŀǰͨ�����ϻ�û��ʲô�ٸ����飬�����ΰ���������\n");
	
	if (me->query_condition("job_busy"))
                return notify_fail("�������������æ�������أ�\n");
                
        if ( objectp(wenshu = present("tiebu wenshu", me)) )
                return notify_fail("�����ϻ����Ű��أ�����ͨ��(look wenshu)����ѯ��\n");
                
        if (!mapp(target = wanted[arg]) ) {
        	message_vision("$N�ҿ�����һ����ˡ�"+arg+"���ķ�ש���˿����ǵ����˶��������ۣ�������������"+(random(2)?"����":"����")+"�ɣ���\n", me);
        	return 1;
        }
        
// û����wenshu�����ģ���5���㡣
        if ( !intp(i = target["wenshu"]) )
        	return notify_fail("�˷������������Ѿ�ȫ���������ˣ�\n");
        	
        str = (string)target["name"];
        exp = (int)me->query("combat_exp"); 
        
        if( exp < 100000 ){
        	message_vision("$N����ǰȥ�������֣���Ȼ�������������ɷ�Ļ����ŵ�һ�°������˻�����\n", me);
                return notify_fail("�������룬�����Լ�����㹦�򣬻������˰ɡ�\n"); 
        }
        
        else if( exp > 1500000 )
        	message_vision(HIY"\n$N�ֿ�����������ǰ��Ŀ�⵭����ɨ���˼��۸�ʾ�����΢΢һ�̣���̬����İ�ͨ��"+str+"���������������\n"NOR, me);
        
        else if( exp > 900000 )
        	message_vision(HIY"\n$N�ƿ�Χ�۵����ˣ��ߵ���ǰ��΢΢�����۾�������Ƴ��һ�۸�ʾ�����ֽ���ͨ��"+str+"���������������˻��С�\n"NOR, me);
        
        else if( exp > 300000 )
        	message_vision(HIY"\n$N����ǰȥ���˿�����ৡ���һ�°�ͨ��"+str+"���������������ת���߳���Ⱥ��\n"NOR, me);
        
        else 	message_vision(HIY"\n$N׳��׳���������ο����ˣ�������ǰ�������˿�����������һ�½��ŵ����飬���¿��˿������İ��������������\n"NOR, me);
        
        str = "\t"+str+"("+capitalize(arg)+")\n";
        str += "\t"+chinese_number(target["age"])+"��"+target["gender"]+"���书"+target["level"]+"\n";
        str += "\t����"+target["act"]+"�����һ�γ�����"+target["place"]+"������\n";
        str += "\t"+target["action"]+"���ͽ�"+MONEY_D->money_str(target["reward"]*10)+"��\n\n";
        str += "\t\t\t֪������\n\n";
        
        wenshu = new(MISC_D("gf_wenshu"));
        if (!wenshu || !clonep(wenshu) )
        	return notify_fail("������֪ͨ��ʦ��GF_job -> wenshu doest not exist! \n");
        i--;
        wenshu->set("long", WHT"����һ���������飬���Ծв�(jubu)���ˣ�������һ�����񣬵�����һ��С�֣�\n\n"NOR+str);
        wenshu->set("target", target);
        wenshu->set("target/id", arg);
        wenshu->move(me);
        
        if( i <= 0 ) del_wanted(arg);
        return 1;
}

string *wheres=({
"/d/emei/xiaowu",		"/d/wudang/xiaolu1",		"/d/xiangyang/zhuquemen",
"/d/xiangyang/hanshui1",	"/d/jiaxing/nanhu",		"/d/xueshan/xuelu2",
"/d/xueshan/houzidong",		"/d/suzhou/lingyansi",		"/d/suzhou/liuyuan",
"/d/jiaxing/tieqiang",		"/d/hz/longjing",		"/d/hz/huanglong",
"/d/hz/yuhuang",		"/d/hz/tianxiang",		"/d/miaojiang/jiedao4",
"/d/foshan/duchang",		"/d/huanghe/shulin5",		"/d/hz/changlang1",
"/d/hz/yuquan",			"/d/hz/longjing",		"/d/xingxiu/shamo3",
"/d/wudang/xuanyue",		"/d/emei/guanyinqiao",		"/d/emei/basipan3",
"/d/tiezhang/shanmen",		"/d/tiezhang/hclu",		"/d/xueshan/huilang4",
"/d/emei/caopeng",		"/d/mingjiao/bishui",		"/d/mingjiao/shanting",
"/d/fuzhou/haigang",		"/d/fuzhou/laozhai",		"/d/xingxiu/shamo2",
"/d/jiaxing/nanhu",		"/d/village/caidi",		"/d/shaolin/songshu2",
"/d/xiangyang/tanxi",		"/d/huashan/husun",		"/d/huashan/yunu",
"/d/mr/yanziwu/xiaojing2",	"/d/mr/mtl/liulin",		"/d/suzhou/shihu",
"/d/suzhou/xuanmiaoguan",	"/d/suzhou/zijinan",		"/d/hengshan/cuiping2",
"/d/hengshan/guolaoling",	"/d/shaolin/talin1",		"/d/wudang/houshan/husunchou",
"/d/shaolin/shanlu8",		"/d/xueshan/shanlu7",		"/d/foshan/road10",
"/d/foshan/xiaolu2",		"/d/emei/jiulaodong",		"/d/hengshan/beiyuemiao",
"/d/gb/xinglin2",		"/d/city/shangang",		"/d/fuzhou/zhongxin",
"/d/huanghe/huanghe4",		"/d/lanzhou/shamo",		"/d/emei/gudelin3",
"/d/cangzhou/dongjie1",		"/d/tanggu/center",		"/d/putian/xl6",
"/d/dali/wuliang/songlin6",	"/d/gumu/xuantie/linhai8",	"/d/gumu/jqg/zhulin5",
"/d/tianshan/dadao6",		"/d/tianshan/shanjin5",		"/d/hmy/changlang",
"/d/hmy/taohua",		"/d/kunlun/shanlin2",		"/d/thd/guiyun/jiugong2",
});

private int random_goto(object ob)
{
	object room;
	int i;
	i = random(sizeof(wheres));
	if( !objectp(room= find_object(wheres[i])) ){
		if( !objectp(room= load_object(wheres[i])) ){
			destruct(ob);
			log_file("job/gfbug",sprintf("GF_wanted.c loading "+wheres[i]+" ʧ�ܡ�\n"));
			return 0;
		}
		if( ob->move(room) ) return 1;
		else {
			destruct(ob);
			log_file("job/gfbug", sprintf("GF_wanted.c NPC goto "+wheres[i]+" ʧ�ܡ�\n"));
		}
	}
	if( ob->move(room) ) return 1;
	else {
		destruct(ob);
		log_file("job/gfbug",sprintf("GF_wanted.c NPC goto "+wheres[i]+" ʧ�ܡ�\n"));
		return 0;
	}
}

private void creat_npc(object *obs)
{
	object player, ob, room;
	string room_name;
	
	ob = new(WANTED_NPC);
	ob->copy_random_player(obs);
	
	if( random(4) != 1 || !sizeof(obs) ){
		random_goto(ob);
	}
	
	else {
		player = obs[random(sizeof(obs))];
		if( environment(player)->is_character() )	
			room = environment(environment(player));
	
		if (wiz_level(player)
		|| player->is_ghost()
		|| !living(player)
		|| !objectp(room)
		|| strsrch(room_name = base_name(room),"/d/") != 0
		|| strsrch(room_name, "/d/wizard/") == 0
		|| strsrch(room_name, "/d/wuguan/") == 0
		|| strsrch(room_name, "/d/death/") == 0) 
        		random_goto(ob);
	
		else if( !ob->move(room) ){
			destruct(ob);
			log_file("job/gfbug", sprintf("GF_wanted.c -> creat_wanted() -> NPC goto ʧ�ܡ�\n"));
			return;
		}
	}
	if( ob ){
		if( do_wanted(ob, 0) ){
			modify_list(0);
			return;
		}
		
		else{
			destruct(ob);
			return notify_fail("Gf_wanted.c -> do_wanted() failed!\n");
		}
	}
	else return notify_fail("Gf_wanted.c -> failed to creat wanted ob !\n");
}


void create()
{
	object *obs;
	modify_list(1);

        remove_call_out("create");
        call_out("create", 800+random(400));

	obs = filter_array(users(), (:  environment($1) && !wizardp($1) && ($1->query("registered") > 1) && $1->query_temp("user_type") != "worker" :));
	if( !obs || sizeof(obs) < 1 ) return;

	creat_npc(obs);
	creat_npc(obs);
	creat_npc(obs);
	creat_npc(obs);
	creat_npc(obs);
	creat_npc(obs);
  creat_npc(obs);
	tell_room(WANTED_ROOM, "\n�������������������ۣ��ڸ�ʾǰæ����һ��\n\n");
 message("system",HIR"\n������֪��ͨ�桿�����ж����������ң����λ�������������ٸ���ȡ�������飬Э�����˵ȼ��ù鰸��\n\n"NOR, users());
}
