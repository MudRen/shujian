
#include <ansi.h>
#define ZHAOQIN_DIR "/d/tanggu/"
//�ļ�Ŀ¼
#define BIWU_USER ZHAOQIN_DIR"npc/copy_user.c"
#define LEITAINPC ZHAOQIN_DIR"npc/npc_leitai.c"
inherit ROOM;
void mu_unset_player(int i);
void mu_set_player(object me,int i);
void mu_set_station(int i);
void create()
{
        set("short", HIG"������̨"NOR);
        set("long", "�����Ǳ������׵���̨�����������ӭ��Ʈ���̨���ܼ�����Χ�۵���Ⱥ����
ߺ�������ģ�����Ц���ģ����������ĵ����ˡ���̨һ�ǹ���һ�����ӣ�paizi����\n");
        set("no_death", 1);
        set("no_get_from", 1); 
        set("no_sleep_room", 1);
        set("dest_room", ZHAOQIN_DIR+"kongchangdi"); 
        set("objects", ([    
               LEITAINPC : 1,
        ]));

        set("item_desc", ([            
			"paizi" : "\n�����������̨���ƣ���˫����׼����( ok )���Ժ�ʼ���䡣\n",      
        ]));
        setup(); 
}
void init()
{
	object me;

	me = this_player();
	if (!userp(me)) return;
	if (!wizardp(me) && !me->query_temp("quest/bwzh/leitai")){
		message_vision("ͻȻ�ɳ�һ˫��ţ���$N����̨�����˳�ȥ��\n", me);
		me->move("/d/city/chmiao");
		message_vision("��������������һ����$N���˴���̨�����˳�����\n", me);
		return;
	}
	
	if (!this_object()->query_temp("quest/bwzh/leitai") 
	&& base_name(me) == BIWU_USER)
	{
		me->quit(me);
		return;
	}	
	if (userp(me)) message_vision("$N����ææ���߽���������̨��\n", me);
	if(me->query_temp("quest/bwzh/leitai") && !wizardp(me) )
	{
		remove_call_out("leaving");
		call_out("leaving",150);
		remove_call_out("auto_kill");
		call_out("auto_kill",45);
	}	
	add_action("do_open", "xinxi");
	add_action("do_ok", "ok");
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
	                          "kill", "fight", "study", "practice", "exercise", "halt", 
	                          "quit", "save", "throw", "rumor", "tell", "mm", "reply",
	                          "chat", "rumor", "party", "shout", "suicide", "yield"}));
}

int do_action(string arg)
{
	object ob,me;
	me= this_player();
	if(me->query("link_ob")) 
		ob=me->query("link_ob");
	if(!wizardp(me)){
		if(ob && wizardp(ob))
			return 0;
		else 
		{
			write("��̨��ֻ�ܱ��䣬�벻Ҫ������ص��£�\n");
			return 1;
		}
	}
	else return 0;
}

int open = 1;

int do_open(string arg)
{
	object me = this_player();
	
	if( !wizardp(me))
		return notify_fail("ֻ����ʦ���ܴ���̨��Ϣ��\n");   
	
	if( !arg || arg == "" || arg != "open") 
		return notify_fail("Ŀǰ����̨��Ϣ״���ǣ�"+(open == 0?"close":"open")+"\n");
	
	if( arg == "open" ){
		open = 1;
		message("leitai", HIY +"\n��"+environment(me)->query("short")+"��̨�������Ŵ���̨�����Ϣ����ϣ������������� set block_leitai ��\n\n"NOR, users());
		return notify_fail("�������̨����Ϣ״����\n");
	}
	
	if( arg == "close" ){
		open = 0;
		message("leitai", HIY +"\n��"+environment(me)->query("short")+HIY"��"NOR+"���رմ���̨�����Ϣ��\n\n"NOR, users());
		return notify_fail("��ر�����̨����Ϣ״����\n");
	}
	
	else return notify_fail("������趨��̨��Ϣ״���� open (�����˶��ܿ������) ���� close (ֻ�п�̨���˲ſ������)\n");
}

void end_fight(object me, object ob, string fam)
{
	string fam2, color;
	object link_me,link_ob;
	link_ob = ob->query("link_ob");
	link_me = me->query("link_ob");

	remove_call_out("auto_kill");
	remove_call_out("leaving");

	fam2 = ob->query("family/family_name")?ob->query("family/family_name"):"ƽ�����";
	color = ob->query("color")?ob->query("color")+" ":" ";
	fam2 = HIW+fam2+color+NOR+ ob->name(1) + "(" + capitalize(ob->query("id")) + ")";
	message_vision("\n"+fam+" �� "+fam2+" ���ܡ�\n", me, ob);
	if( open > 0 )
		message("leitai", HIY +"\n��"+environment(me)->query("short")+HIY"��"NOR+"�����Ѿ�����ʤ����"+ fam+HIY" �� "+fam2+HIY" ���ܣ�\n\n"NOR, 
		filter_array(users(), (:  !$1->query("env/block_leitai") :)));
	log_file("quest/zhaoqin",sprintf(HIC"%-8s%-10s ����%s(%s)end_fight"NOR, ob->name(1), ob->query("id"), me->name(1), me->query("id")));

	mu_set_station(5);//��������
    if(link_ob->query_temp("quest/bwzh/biwu_host") || ob->query_temp("quest/bwzh/biwu_host"))//���ob������������,�������������仯 me���ʧ����
	{
		mu_set_player(me,4);//me ʧ����
		mu_set_player(ob,2);//ob ��������
		link_ob->set_temp("quest/bwzh/biwu_host",1);
		ob->set_temp("quest/bwzh/biwu_host",1);
		mu_unset_player(3);//��ս�����
		me->delete_temp("quest/bwzh");//me ������־
		me->delete_temp("quest/busy");
		link_me->delete_temp("quest/bwzh");//me ������־
		link_me->delete_temp("quest/busy");

		tell_object(ob,HIY"\n��ϲ���������������");
		tell_object(me,HIY"\n��ϧ����ս����δ�ɣ�");
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ������������end_fight\n", ob->name(1), ob->query("id")));
	}
	else//ob��ս�� ��Ϊ���� me ���������Ů����Ϊʧ����
	{
		mu_unset_player(3);//��ս�����	
		if(!me->query_temp("quest/bwzh/hoster") && !link_me->query_temp("quest/bwzh/hoster"))//me ������Ů	
		{
			mu_set_player(me,4);//me ʧ����
			me->delete_temp("quest/bwzh");
			me->delete_temp("quest/busy");
			link_me->delete_temp("quest/bwzh");//me ������־
			link_me->delete_temp("quest/busy");
		}
		else
		{
			me->delete_temp("quest/bwzh/biwu_host");
			link_me->delete_temp("quest/bwzh/biwu_host");
		}
		mu_set_player(ob,2);//ob ��Ϊ����
		ob->set_temp("quest/bwzh/biwu_host",1);//��Ϊ����
		ob->delete_temp("quest/bwzh/biwu_challenge");
		link_ob->set_temp("quest/bwzh/biwu_host",1);//��Ϊ����
		link_ob->delete_temp("quest/bwzh/biwu_challenge");
		tell_object(ob,HIY"\n��ϲ����ս�����ɹ���");
		tell_object(me,HIY"\n��ϧ����������ʧ�ܣ�");
		log_file("quest/zhaoqin",sprintf("%-8s%-10s �����½�����end_fight\n", ob->name(1), ob->query("id")));
	}
	this_object()->delete_temp("quest/bwzh/leitai");
}
       
int start_biwu(object fighter, object fighter2, int num)
{
	object *ob;
	int i;
	
	if( !fighter || environment(fighter) != this_object()){
		if(fighter2) fighter2->quit(fighter2);
		tell_room(this_object(), HIR"\n"+this_object()->query("short")+"������ֹ��\n"NOR);
		return 1;
	}
	
	if( !fighter2 || environment(fighter2) != this_object()){
		if(fighter) fighter->quit(fighter);
		tell_room(this_object(), HIR"\n"+this_object()->query("short")+"������ֹ��\n"NOR);
		return 1;
	}

	num++;
	
	if( num <= 1 ){
		fighter->set_temp("last_damage_from", fighter2);
		fighter2->set_temp("last_damage_from", fighter);

		ob = all_inventory(this_object());
		i = sizeof(ob);
		while (i--) {
			if(!userp(ob[i]) && !ob[i]->query_temp("leitai"))
				destruct(ob[i]);
		}	
		tell_room(this_object(), HIR+"\n\t"+this_object()->query("short")+HIR"�ϴ�����"+chinese_number(1)+"�����죡\n\n"NOR);
	}
	
	else if( num >= 3 ){
		message_vision(HIR"ֻ�����������죬$N��$n������ʽ��ʼ��\n"NOR, fighter, fighter2);
		if( open > 0 )
			message("leitai", HIR +"\n��"NOR+this_object()->query("short")+HIR"��"NOR+HIY"����λ����ͬ����" NOR+fighter->short(1)
			                    +HIY" \n\t      ��"NOR+fighter2->short(1)+HIY" ����������̨����ʽ��ʼ��\n\n"NOR, 
          		filter_array(users(), (:  !$1->query("env/block_leitai") :)));
		else message_vision(HIR +"\n��"+this_object()->query("short")+HIR"��"NOR+HIY"����λ����ͬ����" NOR+fighter->short(1)
			                    +HIY" \n\t      ��"NOR+fighter2->short(1)+HIY" ����������̨����ʽ��ʼ��\n\n"NOR, 
          		fighter, fighter2);
          		
		fighter->delete("last_death_time");
		fighter2->delete("last_death_time");
		fighter2->kill_ob(fighter);
		fighter->kill_ob(fighter2);
		return 1;
	}
	else tell_room(this_object(), HIR+"\n\t"+this_object()->query("short")+HIR"�ϴ�����"+chinese_number(num)+"�����죡\n\n"NOR);

	remove_call_out("start_biwu");
	call_out("start_biwu", 4 , fighter, fighter2, num);
	return 1;
}
void auto_kill()
{
	object *ob_list;
	object me,ob;
	int p;

	remove_call_out("auto_kill");
	ob_list = filter_array(children(BIWU_USER), (: clonep :));

	if(!sizeof(ob_list)) return;

	for(p=0; p<sizeof(ob_list); p++) 
	{
		if(!ob_list[p]->query_temp("quest/bwzh/leitai")) continue;
		if(ob_list[p]->query_temp("quest/bwzh/biwu_host") )
			me=ob_list[p];
		if(ob_list[p]->query_temp("quest/bwzh/biwu_challenge"))
			ob=ob_list[p];
	}
	log_file("quest/zhaoqin",sprintf(HIY"%-10s ִ�� auto_kill\n"NOR, this_object()->query("short")));

	if(me && ob && (!me->is_fighting()|| !ob->is_fighting()))
	{
		remove_call_out("auto_kill");
		remove_call_out("start_biwu");
		me->set_temp("quest/bwzh/leitai", 2);
		ob->set_temp("quest/bwzh/leitai", 2);
		message_vision(HIW"\n$N���˿�$n����Цһ�����ѵ�"+ob->query("name")+"����ս�����ң����ǵ�С��\n\n"NOR, me,ob);
		message_vision(HIW"\nͻȻ�ӽ�����ܳ�һ����Ӱ���ٺ���Ц����$N��$n����������ʽ��ʼ����\n\n"NOR, me,ob);
		message_vision(HIR"\n"NOR, me, ob);
		if( open > 0 )
			message("leitai", HIR +"\n��"NOR+this_object()->query("short")+HIR"��"NOR+HIY"����λ����ͬ����"NOR+me->short(1)
                   			   +HIY" \n\t      ��"NOR+ob->short(1)+HIY" ����������̨����ʽ��ʼ��\n\n"NOR, 
          		filter_array(users(), (:  !$1->query("env/block_leitai") :)));
		else message_vision(HIR +"\n��"NOR+this_object()->query("short")+HIR"��"NOR+HIY"����λ����ͬ����"NOR+me->short(1)
			                   +HIY" \n\t      ��"NOR+ob->short(1)+HIY" ����������̨����ʽ��ʼ��\n\n"NOR, 
          		me, ob);
          		
		me->delete("last_death_time");
		ob->delete("last_death_time");
		me->kill_ob(ob);
		ob->kill_ob(me);
	}
	return;
}	

int do_ok()
{
	object ob, me = this_player();

	if(!me->query_temp("quest/bwzh/leitai") || base_name(me) != __DIR__"npc/copy_user")
		return notify_fail("������ֻ����̨�����ѡ�ֿ��á�\n");
    
	if(me->query_temp("quest/bwzh/leitai") == 2)
		return notify_fail("���Ѿ�������ս�ˡ�\n");
		
	me->set_temp("quest/bwzh/leitai", 2);
	if(!objectp(ob = this_object()->query_temp("fighter")))
	{
		this_object()->set_temp("fighter", me);
		message_vision("\n$N���˸��ϣ�"+RANK_D->query_self(me)+"�Ѿ�׼�����ˣ�Ը�����κ���ս��\n", me);
	}
	
	else if(environment(ob) != this_object()){
		ob->quit(ob);
		this_object()->set_temp("fighter", me);
		message_vision("\n$N���˸��ϣ�"+RANK_D->query_self(me)+"�Ѿ�׼�����ˣ�Ը�����κ���ս��\n", me);
	}
	else {
		this_object()->delete_temp("fighter");
		message_vision("\n$N��$n���˸��ϣ�"+RANK_D->query_self(me)+"ð������ս"+RANK_D->query_respect(ob)+"��\n", me, ob);
		remove_call_out("auto_kill");	
		start_biwu(me, ob, 0);
	}
	return 1;
}

void leaving()
{
	object *ob_list;
	object link_ob,ob,me;
	string fam1,fam2,color;
	int p,i=0;
	remove_call_out("leaving");
	ob_list = filter_array(children(BIWU_USER), (: clonep :));

	if(!sizeof(ob_list)) return;

	log_file("quest/zhaoqin",sprintf(HIY"%-10s ִ�� leaving\n"NOR, this_object()->query("short")));

	for(p=0; p<sizeof(ob_list); p++) 
	{
		if(ob_list[p]->is_fighting()) continue;
		if(!ob_list[p]->query_temp("quest/bwzh/leitai")) continue;
		i=i+1;
		if(ob_list[p]->query_temp("quest/bwzh/biwu_host") )
		{
			ob=ob_list[p];
			tell_object(ob_list[p],HIR"ʱ�䵽��������ƽ���㡣���������������λ��\n"NOR);
			mu_set_station(5);//��������
			mu_set_player(ob_list[p],2);//ob ��������
			log_file("quest/zhaoqin",sprintf("%-8s%-10s ������������leaving\n", ob_list[p]->name(1), ob_list[p]->query("id")));
		}
		if(ob_list[p]->query_temp("quest/bwzh/biwu_challenge"))
		{
			me=ob_list[p];
			tell_object(ob_list[p],HIR"ʱ�䵽��������ƽ���㡣����ս����ʧ�ܣ�\n"NOR);
			link_ob=ob_list[p]->query("link_ob");
			ob_list[p]->delete_temp("quest/bwzh");//me ������־
			ob_list[p]->delete_temp("quest/busy");
			link_ob->delete_temp("quest/bwzh");//me ������־
			link_ob->delete_temp("quest/busy");
			mu_unset_player(3);//��ս�����
			mu_set_station(5);//��������
			mu_set_player(ob_list[p],4);//me ʧ����
		}
		ob_list[p]->quit(ob_list[p]);
	}
	if(me && ob) 
	{
		fam1 = me->query("family/family_name")?me->query("family/family_name"):"ƽ�����";
		color = me->query("color")?me->query("color")+" ":" ";
		fam1 = HIW+fam2+color+NOR+ me->name(1) + "(" + capitalize(me->query("id")) + ")";

		fam2 = ob->query("family/family_name")?ob->query("family/family_name"):"ƽ�����";
		color = ob->query("color")?ob->query("color")+" ":" ";
		fam2 = HIW+fam2+color+NOR+ ob->name(1) + "(" + capitalize(ob->query("id")) + ")";
		message_vision(HIW"\n$Nһ���߰�����̬����Ȼû�˸�����ս������"+RANK_D->query_self(ob)+"���������޵��ˣ�\n\n"NOR, ob);
		message_vision("\n"+fam1+" �� "+fam2+" ƽ�֡�\n", me, ob);
	if( open > 0 )
		message("leitai", HIY +"\n��"+environment(me)->query("short")+HIY"��"NOR+""+ fam1+HIY" �� "+fam2+HIY" ��Ȼƽ�֣���"NOR+me->query("name")+HIY"ʧ���㣡\n\n"NOR, 
		filter_array(users(), (:  !$1->query("env/block_leitai") :)));
	}
	
	if(!i)
	{
		remove_call_out("leaving");
		call_out("leaving",120);
	}
	return;
}	

int load_user(object player)
{
	object user;
	string arg, color;

	arg = player->query("id");
	
	if (!arg 
	|| this_object()->query_temp("quest/bwzh/leitai") > 1
	|| base_name(player) ==  BIWU_USER)
		return 0;  

	seteuid(arg);
	user = new( BIWU_USER);   // ȥ����save()����̨�е�һ�кͱ����޹ء�
	user->set_name("", ({ arg }));
	if(!user->restore()) {
		destruct(user);
		write("User Restore Error����֪ͨ��ʦ��\n");
		return 0;
	}

	user->setup();		
	user->set_temp("quest/bwzh/leitai", 1);    
	exec(user, player);
	user->set("link_ob", player);
	this_object()->add_temp("quest/bwzh/leitai", 1);
	user->move(this_object());
	user->clear_condition();
	user->reincarnate();
	user->delete_temp("combat_yield");
	user->set("channels", ({ "rumor", "err" }) );
	tell_object(user, YEL"����������̨��Ŀǰ�������״̬�С�\n"NOR"
��Ҫ���������Ʒ������ "YEL"NA"NOR" ��
�����׼���������"YEL" OK "NOR"��\n\n");

	arg = user->query("family/family_name")?user->query("family/family_name"):"ƽ�����";
	color = user->query("color")?user->query("color")+" ":" ";
        arg = HIW+arg+NOR+" "+color + user->name(1) + NOR "(" + capitalize(user->query("id")) + ")";
	tell_room(this_object(), arg + YEL"���������̨��\n\n"NOR, ({ user }));
	player->set_leader(0);
	if(player->query_temp("quest/bwzh/hoster"))
	{
		user->set_temp("quest/bwzh/hoster",1);
		user->set_temp("quest/bwzh/biwu_host",1);
		tell_object(user, HIR"�������ǵ�һ��������\n"NOR);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ��Ů������̨load_user\n", player->name(1), player->query("id")));
	}
	else if(player->query_temp("quest/bwzh/biwu_challenge"))
	{
		user->set_temp("quest/bwzh/biwu_challenge",1);
		tell_object(user, HIR"��������ս������Ҫ�������˹飬�ͱ���ȫ���Ը���\n"NOR);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ս������̨load_user\n", player->name(1), player->query("id")));
	}
	else if(player->query_temp("quest/bwzh/biwu_host"))
	{
		user->set_temp("quest/bwzh/biwu_host",1);
		tell_object(user, HIR"��������������Ҫ�������˹飬�ͱ���ȫ���Ը���\n"NOR);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ����������̨load_user\n", player->name(1), player->query("id")));
	}
	else 
	{
		log_file("quest/zhaoqin",sprintf(HIR"%-8s%-10s ����������̨load_user\n"NOR, player->name(1), player->query("id")));
	}
	return 1;
}

void mu_unset_player(int i)
//0 ȫ�� 1 host 2 winner 3 challenge 4 fail 
{
	object room,obj;
	if (!(room = find_object(query("dest_room"))))
		room = load_object(query("dest_room"));
	if(!room) return;
	obj=present("mu nianci",room);
	if(!obj) return;
	if(i==0) obj->delete("bwzh");
	else if(i==1) obj->delete("bwzh/host_player");
	else if(i==2) obj->delete("bwzh/winner_player");
	else if(i==3) obj->delete("bwzh/challenge_player");
	else if(i==4) obj->delete("bwzh/fail_player");
	
	if(i==0) log_file("quest/zhaoqin",sprintf("%-8s%-10s ��־ȫ�����mu_unset_player", obj->name(1), obj->query("id")));
	else if(i==1) log_file("quest/zhaoqin",sprintf("%-8s%-10s ��Ů��־���mu_unset_player\n", obj->name(1), obj->query("id")));
	else if(i==2) log_file("quest/zhaoqin",sprintf("%-8s%-10s ������־���mu_unset_player\n", obj->name(1), obj->query("id")));
	else if(i==3) log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ս�������mu_unset_player\n", obj->name(1), obj->query("id")));
	else if(i==4) log_file("quest/zhaoqin",sprintf("%-8s%-10s ʧ���������mu_unset_player\n", obj->name(1), obj->query("id")));

	return;
}
void mu_set_player(object me,int i)
//1 host 2 winner 3 challenge 4 fail 5 station
{
	object room,obj,link_me;
	if (!(room = find_object(query("dest_room"))))
		room = load_object(query("dest_room"));
	if(!room) return;
	obj=present("mu nianci",room);
	if(!obj) return;
	if(!me) return;
	if(!me->query("link_ob"))
	{
		log_file("quest/zhaoqin",sprintf("%-8s%-10s û��link_ob��־mu_set_player\n", me->name(1), me->query("id")));
		return;
	}
	link_me = me->query("link_ob");
	if(i==5)
		obj->set("station",5);
	else if(i==1) 
	{
		obj->set("bwzh/host_player/name",me->query("name"));
		obj->set("bwzh/host_player/id",me->query("id"));
		obj->set("bwzh/host_player/object",link_me);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ������Ů%s(%s) mu_set_player\n", obj->name(1), obj->query("id"),obj->query("bwzh/host_player/name"),obj->query("bwzh/host_player/id")));
	}
	else if(i==2)
	{
		obj->set("bwzh/winner_player/name",me->query("name"));
		obj->set("bwzh/winner_player/id",me->query("id"));
		obj->set("bwzh/winner_player/object",link_me);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ��������%s(%s)mu_set_player\n", obj->name(1), obj->query("id"),obj->query("bwzh/winner_player/name"),obj->query("bwzh/winner_player/id")));
	}
	else if(i==3)
	{
		obj->set("bwzh/challenge_player/name",me->query("name"));
		obj->set("bwzh/challenge_player/id",me->query("id"));
		obj->set("bwzh/challenge_player/object",link_me);
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ��ս��%s(%s)mu_set_player\n", obj->name(1), obj->query("id"),obj->query("bwzh/challenge_player/name"),obj->query("bwzh/challenge_player/id")));
	}
	else if(i==4)
	{
		obj->set("bwzh/fail_player/name",me->query("name"));
		obj->set("bwzh/fail_player/id",me->query("id"));
		log_file("quest/zhaoqin",sprintf("%-8s%-10s ʧ����%s(%s)mu_set_player\n", obj->name(1), obj->query("id"),obj->query("bwzh/fail_player/name"),obj->query("bwzh/fail_player/id")));
	}
	return;
}
void mu_set_station(int i)
{
	object room,obj;
	if (!(room = find_object(query("dest_room"))))
		room = load_object(query("dest_room"));
	if(!room) return;
	obj=present("mu nianci",room);
	if(!obj) return;
	obj->set("station",i);
	log_file("quest/zhaoqin",sprintf("%-8s%-10s ����״̬Ϊ%d mu_set_station\n", obj->name(1), obj->query("id"),i));
	return;
}



