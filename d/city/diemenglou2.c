//add by tangfeng
//2005.3
#include <ansi.h>
#define Description "һ��СС�ĸ�¥������Ϊ�꣬��Ϊ�ǣ�����Ϊ������Ϊ·�����ϼ���\n����ȥ�е����ҵĲ�ϯ������һ�Ⱥڶ�����С���š���ֻ������ʰ�쵣���\n¥��֮�������ȥ��ǽ�Ϲ���һ���ݰ��ԣ�"+HIR"cao bagua"NOR+"�������������һ��\nʯ̳��"+HIW"shitan"NOR+"��������ģ������Щʲô�Ƶġ�\n"
#define BOOK    "/clone/gift/book"      //��
#define MIC     "/clone/gift/danwan"    //ҩ
#define MON     "/clone/gift/money"     //Ǯ
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define DAZAO   "/clone/gift/imbue"     //�������

inherit ROOM;
string look_bagua();
string look_shitan();
int do_qidong(string arg);
void destruct_person();
void copy_npc(object me,int x);
void random_gift(object me);
int sort_user(object ob1, object ob2);
#define Score_Limit 3000
#define Gift_Limit 800

#include "/d/city/diemenglou_poison.h";
#include "/d/city/diemenglou_party.h";
#include "/d/city/diemenglou.h";

void create()
{
	set("short",HIW"����¥��¥"NOR);
	set("long",Description);
	set("exits",([
		//"up" : __DIR__"diemenglou3",
		"down" : __DIR__"diemenglou1",
	]));
	set("item_desc",([            
            "cao bagua" : (: look_bagua :),
            "shitan" : (: look_shitan :),
        ]));
	set("quest",1);
	set("no_death",1);
	set("no_get_from", 1); 
	set("no_sleep_room", 1);
	set("coor/x",80);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}
void init()
{
	object me;
	me = this_player();
	if(userp(me) && !wizardp(me)
		&& (me->query_condition("killer")
		    ||me->query_condition("job_busy")
			|| !me->query_temp("quest/special/second_floor")
			|| !me->query_temp("quest/special/up")))
	{
		me->remove_all_killer();
		me->revive();
		me->reincarnate();
		message_vision(HIC"\nͻȻ$N��ǰһ�����ܱߵ�һ��������á�$N�����մ����졣\n"NOR,me); 
		me->move("/d/city/lxs");
		message_vision(HIY"$Nֻ����һ�����ʣ���Ȼ�ƺ���ƮƮȻ���뿪���Ǹ�С¥��\n"NOR, me);
		me->delete_temp("quest/special");
		me->start_busy(2);
		return;
	}
	add_action("do_qidong", ({"qidong"}));
	add_action("do_liaoshang", ({"liaoshang"}));
	add_action("do_chakan", ({"chakan"}));
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                              "kill", "fight", "study", "practice", "exercise", "halt", "ask","whisper",
	                          "quit", "save", "throw", "suicide"}));
	if(!wizardp(this_player()) && userp(this_player()))
	{
		if(me->query_temp("quest/special/second_floor"))
			call_out("must_dream",360,me);
		else
			call_out("must_dream",1,me);
	}
}
void must_dream(object me)
{
	if(!me) return;
	if(!userp(me)) return;
	if(!me->query_temp("quest/special/second_floor") || !me->is_fighting())
	{
		me->remove_all_killer();
		me->reincarnate();
		message_vision(HIC"\nͻȻ$N��ǰһ�ң��ƺ�������$N������ʲô�󷨣������մ����졣\n"NOR,me); 
		message_vision(HIY"$Nֻ����һ�����ʣ���Ȼ�ƺ���ƮƮȻ���뿪���ε���¥��\n"NOR, me);
		me->move(__DIR__"diemenglou1");
		message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
        me->start_busy(1);
		me->delete_temp("quest/special/second_floor");
		set("long",Description);
		remove_call_out("again_check");
		call_out("again_check",3,me);//Ϊ�˷�ֹdazhuan ���Ƶ�pfm ���ֱ������������bug
		return;
	}
}
int do_action(string arg)
{
	if(!wizardp(this_player())){
		write("�ε���¥ֻ�ܱ��䣬�벻Ҫ������ص��£�\n");
		return 1;
	}
	else return 0;
}
string look_bagua()
{
    	object me;
		string str;
    	me = this_player();
		if(me->is_fighting()) 
			return "����æ���ء�\n";
    	if (me->is_busy()) 
          	return "����æ���ء�\n";
    	me->start_busy(2);
		    str  = HIR"\n               ����ĺ�����ң���������Բ�������\n"NOR;

			str += HIW"\n�����������ʹ�� qidongָ�����������󷨣������齣����ѧ�Ĵ�������\n"NOR;
			str += HIW"�������á�Ŀǰ���ŵ�ָ���ʽ�У�\n"NOR;
			str += HIY"\nqidong |<����>|<����>|<�Ѷȵȼ�>|<�����Ƿ�>|"NOR+"��"+HIM"��ָ����������ս��\n"NOR;
			str += RED"\n���ɱ��Ϊ��\n"NOR;
		    str += WHT"1--�䵱 2--��ɽ 3--��ɽ 4--��Ĺ 5--ؤ�� 6--���� 7--������ 8--Ľ��\n"NOR;
			str += WHT"9--������ 10--���� 11--���� 12--���� 13--�һ��� 14--���� 15--����\n"NOR;
			str += WHT"16--���� 17--������ȫ 18--��󡹦 19--��а�� 20--���߽�\n"NOR;
			str += HBRED"\n�Ѷȵȼ���1-9�������趨Ϊ1������Ϊ2�����Ϊ3������������10�ˡ�\n"NOR;
        tell_object(me,str);
    	return "";
}
string look_shitan()
{
    	object me;
		string str;
    	me = this_player();
		if(me->is_fighting()) 
			return "����æ���ء�\n";
    	if (me->is_busy()) 
          	return "����æ���ء�\n";
    	me->start_busy(2);
			str = HBYEL"�ƺ��к��������ڴ˵�����һ���о������ⷢ�ּ������ܣ��ؿ���ˣ�\n"NOR;
			str += CYN"�������Ѫ����1/3������ʹ��"+HIC"liaoshang"NOR+CYN"����͵����˸���һ���ָ���\n";
			str += "���ʹ��"+HIC"chakan"NOR+CYN"������������˽�����λ��֡���ǰ���ֺͽ��������\n";
			str += ""+HIC"chakan top"NOR+CYN"���Բ鿴ǰʮ�����θ��֡���ʦ����ʹ��"+HIC"chakan <player>"NOR+CYN"\n"NOR;
        tell_object(me,str);
    	return "";
}
int do_qidong(string arg)
{
	object me = this_player();
	int i,p,j,k;
	int a=1,b=0,c=100,d=9,e=0,f=0;
	// a  �߼�/�ͼ��书 b ����/���� c pfm���� d ����ӳ� e hubo f lbwb
	if(me->query_temp("killer")) 
		return notify_fail(RED"���ƺ��͹ٸ�����Щ���ڡ�\n"NOR);
	if(!me->query_temp("quest/special/up")) 
        return notify_fail(RED"���޷������󷨡�\n"NOR);
	if(!me->query_temp("quest/special/second_floor")) 
        return notify_fail(RED"���޷������󷨡�\n"NOR);
   if(me->query_temp("quest/special/score")>199) 
        return notify_fail(RED"����ս��̫��Ķ��֣��ƺ��е�ƣ�ͣ��������û�����Ϣһ�°ɡ�\n"NOR);
   if((int)me->query("quest/special/score")<1000) 
        return notify_fail(RED"����þ�ƾ�Լ���ô���ս����������ս����Ķ��֣����û��ǲ���Ϊ�\n"NOR);

    if(me->is_fighting()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
	if(!arg) return notify_fail(HIR"ָ���ʽ��qidong |<���ɱ��>|<������>|<�Ѷȼ���>|<�����Ƿ�>|��\n"NOR);
	if(this_object()->query("busy")) 
		return notify_fail(HIR"��΢��Ϣһ�£�������Ҫʱ�临λ��\n"NOR);
	if(sscanf(arg,"|%d|%d|%d|%d|",i,j,p,k) == 4)
	{   
		if(i>20 || i<1 ) 
			return notify_fail(HIY"ע��ָ�������ɱ�ŵ�ȡֵ��Χ��\n"NOR);
		if(j<2) 
			return notify_fail(HIY"ע��ָ�������������ܵ���2�ˡ�\n"NOR);
		if(j>10 ) 
			return notify_fail(HIY"ע��ָ������������ȡֵ��Χ��\n"NOR);
		if(p<1 || p>10) 
			return notify_fail(HIY"ע��ָ�����Ѷ�ϵ����ȡֵ��Χ��\n"NOR);
		if(k<1 || k>3) 
			return notify_fail(HIY"ע��ָ���п���ϵ����ȡֵ��Χ��\n"NOR);
	
		remove_call_out("must_dream");
        
		if(k==2) b=1;
		else if(k==3) b=random(2);//�����ĸ���
		else if(j==4) e=1;

		if(p<=2)
		{
			a=0;//�ͼ��书��
			c=p*30+random(p*30);
			d=9+random(p*3/2);//��ͬ����exp�����Ѷ�����һ��
		}
		else if(p==3)
		{
			c=(p-2)*30+random((p-2)*30);
			d=7+random(p);//����-11%~11%exp
			e=random(2);//����hubo
		}
		else if(p==4)
		{
			c=(p-2)*30+random((p-2)*30);
			d=9+p-3+random(p-1);//����11%~33%exp
			e=random(2);//����hubo
		}
		else if(p==5)
		{
			d=9+p-2+random(p-4);//����33%~55%exp
			e=1;//����hubo
			f=random(2);
		}
		else if(p==6)
		{
			d=9+p-1+random(p-2);//����66%~88%exp
			e=1;//����hubo
			f=random(2);
		}
		else if(p==7)
		{
			d=9+p+1+random(p-3);//����88%~122%exp
			e=1;//����hubo
			f=1;
		}
		else if(p==8)
		{
			d=9+p+3+random(p-3);//����122%~155%exp
			e=1;//����hubo
			f=1;
		}
		else if(p==9)
		{
			d=9+p+5+random(p-3);//����155%~211%exp
			e=1;//����hubo
			f=1;
		}

		if(c>100) c=100;
		remove_call_out("start");
		remove_call_out("do_start");
		remove_call_out("busy");
		call_out("busy",120);
		this_object()->set("busy",1);
		if(random(2)) message_vision(HIC"$N���ڰ������̡�ֻ�����Ǽ��������\n"NOR, this_player());
		else message_vision(HIC"$N���ڰ������̡�ֻ���ܱ�һ���㱡�\n"NOR, this_player());
		me->set_temp("quest/special/a",a);//�߼��书
		me->set_temp("quest/special/b",b);//��������
		me->set_temp("quest/special/c",c);//pfm ����
		me->set_temp("quest/special/d",d);//����ӳ�
		me->set_temp("quest/special/e",e);//hubo
		me->set_temp("quest/special/f",f);//lbwb
		me->set_temp("quest/special/i",i);//���ɱ��
		me->set_temp("quest/special/j",j);//������
		me->set_temp("quest/special/p",p);//�Ѷ�ϵ��
		call_out("do_start",2,me);
		return 1;
	}
	else return notify_fail(HIR"ָ���ʽ��qidong |<���ɱ��>|<������>|<�Ѷȼ���>|<�����Ƿ�>|��\n"NOR);
}
void busy()
{
  this_object()->delete("busy");
  return;
}
void do_start(object me)
{
	object obj;
	string obj_party;
	mapping my_party;
	if(!me->query_temp("quest/special/up")) 
        return notify_fail(RED"��������ʧ�ܡ�\n"NOR);
	if(!me->query_temp("quest/special/second_floor")) 
        return notify_fail(RED"��������ʧ�ܡ�\n"NOR);

    my_party = get_party_int(me->query_temp("quest/special/i"));
	if(me->query_temp("quest/special/i")<=16)
		obj_party=my_party["party-name"]+"����";
	else obj_party=my_party["party-name"]+"����";
	message_vision(HIG"\nһ��������ܱ߾�ɫȫ�䣬$N�ɻ����ƺ�������ʷ��衣"HIY"\nͻȻ�䣬"+chinese_number(me->query_temp("quest/special/j"))+"��"NOR+my_party["col"]+obj_party+HIY"�������˳�����\n"NOR,me,obj);
    copy_npc(me,1);
	for (int k = 1; k <= (me->query_temp("quest/special/j")-1); k++) 
			copy_npc(me,0);
	remove_call_out("check");
	call_out("check",1,me);
}

void check(object me)
{
 	string obj_party;
	object *obj,*player;
	int i,x=0,p=0;
	mapping my_party;


	if(!me || !living(me)||!present(me,this_object())||me->query("qi")<=1||me->query("jing")<=1||!me->query_temp("quest/special"))  
	{
		remove_call_out("check");
		remove_call_out("must_dream");
		destruct_person();//����npc��ʧ
		obj = all_inventory(this_object());
		for (i = 0; i < sizeof(obj); i++) {
			if (living(obj[i]) || obj[i]->is_character() ) continue;
			if(me && !obj[i]->query("copy_object")) 
			{
				obj[i]->move(me);
				message_vision(HIG"\n$N�ۿ��ŵ��ϵ�"NOR+obj[i]->query("name")+HIG"Ʈɢ��ȥ���������У��ƺ�ҲҪ����һ�㡣\n"NOR,me);
				x=1;
			}
			else
				destruct(obj[i]);
		}         	
		//ʧ�ܺ��ȥ��
		if(userp(me))
		{ 
			if(present(me,this_object()))
			{
				me->remove_all_killer();
				me->revive();
				me->reincarnate();
				destruct_poison(me);//ȥ��
				remove_call_out("busy");
				call_out("busy",5);
				message_vision(HIW"\nͻȻһ�����������$N��$N�ľ�����Ȼȫ���ָ��ˣ�\n"NOR, me);
				message_vision(HIY"$Nֻ����һ�����ʣ���Ȼ�ƺ���ƮƮȻ���뿪���Ǹ�С¥��\n"NOR, me);
				me->move("/d/city/lxs");
                           me->set("quest/special/up/time",time());
				message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
				tell_object(me,HIY"�㻳���Լ�Ҳ�������û�е���һ�������ε�¥�ĵط���\n�ε�¥�����⣬���㣬����ãã���齣�����С���\n"NOR);
				if(x==1) tell_object(me,"��ͻȻ����ԭ���ڵ���¥ʧ�����Ʒ��Ȼ�������ϡ�\n");
				remove_call_out("again_check");
			    call_out("again_check",3,me);//Ϊ�˷�ֹdazhuan ���Ƶ�pfm ���ֱ������������bug
			}
		   	me->delete_temp("quest/special");
    	}
        return;
	}

	player = all_inventory(environment(me));
	for (i = 0; i < sizeof(player); i++) {
		if (!living(player[i]) || player[i] == me) continue;
		if( player[i]->query("id")=="mengdie npc"|| player[i]->query("quest/level")) p++;
	}

	if (p==0)  //ʤ��
	{
		remove_call_out("check");
		if(me)
		{
			my_party = get_party_int(me->query_temp("quest/special/i"));
			me->remove_all_killer();
			destruct_poison(me);//ȥ��
			if(me->query_temp("quest/special/i")<=16)
				obj_party=my_party["party-name"]+"����";
			else obj_party=my_party["party-name"]+"����";
			if(me->query_temp("quest/special/j")) 
				message_vision(HIW"\n������ಫ����$N���ڳɹ�����"+chinese_number(me->query_temp("quest/special/j"))+"�˵�"+my_party["party-name"]+my_party["col"]+my_party["lineup-name"]+HIW"��\n"NOR, me);
			else 
				message_vision(HIW"\n������ಫ����$N���ڳɹ�����"+my_party["party-name"]+my_party["col"]+my_party["lineup-name"]+HIW"��\n"NOR, me);
			message_vision(HIY"����һ�����������$N��$N�������в��ָֻ���\n"NOR, me);
                   me->add("neili",(int)me->query("max_neili")/2);
			if(me->query("neili")>me->query("max_neili")*2) me->set("neili",me->query("max_neili")*2);
			remove_call_out("busy");
			call_out("busy",1);
			remove_call_out("must_dream");
			call_out("must_dream",360,me);
			random_gift(me);//�������
		}
    	return;
	}
	call_out("check",1,me);
}
int valid_leave(object me, string dir)
{
	int i=me->query("quest/special/score");
	int p=me->query("quest/special/third_floor");
	if (me->is_fighting())
		return notify_fail(RED"\nս���У��㾹Ȼ�޷�����\n"NOR);
	if (present("mengdie npc",this_object()))
		return notify_fail(RED"\n�㻹�����С�\n"NOR);
	if ( dir == "up" )
	{
		if(i<Score_Limit)
			return notify_fail(HIR"ͻȻ��Υ����������������������ǰ������λ"+RANK_D->query_respect(me) +"�����ս��������¥�����Ƕ��Ŭ���ɣ�\n"NOR);
		if (i<(p+1)*Score_Limit)
			return notify_fail(HIR"ͻȻ��Υ����������������������ǰ������λ"+RANK_D->query_respect(me) +"����Ȼ���Ѿ��ϴι�"+chinese_number(p)+"�Σ����ǻ�����ҪŬ�����еģ�\n"NOR);
		remove_call_out("must_dream");
		message_vision(HIY"\nͻȻ��Υ�������������������˹�����\n"NOR, me);
		message_vision(CYN"���ͳ���$N΢Ц�ص��˵�ͷ��\n"NOR, me);
		message_vision("����˵������"NOR+RED"��λ"+RANK_D->query_respect(me) +"���벻������˽��˵�ս������ӭ������¥��"NOR+"��\n"NOR, me);
		message_vision(WHT"���ţ����ͽ���һָ��ͻȻһ�����������$N��\n$N�ľ����������������д���Ȼָ���\n"NOR, me);
		message_vision(CYN"������$N���˻��֣�\n"NOR, me);
		me->clear_condition();//
		me->reincarnate();
		remove_call_out("busy");
		call_out("busy",1);
		me->add("neili",me->query("max_neili")/2+random(me->query("max_neili")/2));
		if(me->query("neili")>me->query("max_neili")*2) me->set("neili",me->query("max_neili")*2);
		me->add("quest/special/third_floor",1);
		me->set_temp("quest/special/third_floor",1);
	}
	else if ( dir == "down" )
	{
		message_vision(HIY"\nͻȻ��Υ�������������������˹�����\n"NOR, me);
		message_vision(CYN"���Ͳ���ؿ���$N���ɻ�ص��˵�ͷ��\n"NOR, me);
		message_vision("����˵������"NOR+RED"��λ"+RANK_D->query_respect(me) +"���벻����Ȼ�������ᣡ��Ҫ����û���Ѱ���"NOR+"��\n"NOR, me);
		message_vision(CYN"����̾�˿�������$N���˻��֣�\n"NOR, me);
		remove_call_out("must_dream");
		me->clear_condition();//
		remove_call_out("busy");
		call_out("busy",1);
		me->set_temp("quest/special/up",1);
		me->delete_temp("quest/special/second_floor");
	}
	return ::valid_leave(me, dir);
}

void copy_npc(object me,int x)
{
	int a,b,c,d,e,f,i,j,p,k;
    object obj,*inv;
	mapping my_party;

	if(!me) return;
	if(!me->query_temp("quest/special/up")) return;
	if(!me->query_temp("quest/special/second_floor")) return;
    a=me->query_temp("quest/special/a");
    b=me->query_temp("quest/special/b");
    c=me->query_temp("quest/special/c");
    d=me->query_temp("quest/special/d");
    e=me->query_temp("quest/special/e");
    f=me->query_temp("quest/special/f");
    i=me->query_temp("quest/special/i");
    j=me->query_temp("quest/special/j");
    p=me->query_temp("quest/special/p");

	my_party = get_party_int(i);

	obj=new(__DIR__"npc/mengdie_npc2");
	obj->set("quest/level",p);//
	obj->copy_menpai(({my_party["party"]}),a,b,c);
	obj->set_skills_level((me->query("max_pot")-100)*d/9);
	obj->set_skill(my_party["lineup"],200);//��
	obj->set_skill("literate",200);//����д��
	obj->copy_state();	
	obj->get_npc_name();	

	if(i<=16)
		obj->set("title",my_party["col"]+obj->query("family/family_name")+"����"NOR);
	else obj->set("title",my_party["col"]+obj->query("family/family_name")+NOR);
	if(e==1) obj->set("double_attack",1);
	if(f==1 && i!=13 && i!=17 && i!=19 && i!=4)
	{
		obj->set_skill("lingbo-weibu",(me->query("max_pot")-100)*d/9);
		obj->set("quest/�����˲�/�书/yuxiang",1);
		obj->set("quest/�����˲�/�书/pass",1);
		obj->map_skill("dodge","lingbo-weibu");		
	}
	obj->set("max_qi",me->query("max_qi")*(d+random(3))/9);
	obj->set("eff_qi",obj->query("max_qi"));
	obj->set("qi",obj->query("max_qi"));
	obj->set("max_jing",obj->query("max_qi"));
	obj->set("eff_jing",obj->query("max_qi"));
	obj->set("jing",obj->query("max_qi"));
	obj->set("max_jingli",obj->query("max_qi"));
	obj->set("jingli",obj->query("max_qi"));
	obj->set("max_neili",me->query("max_neili")*(d+random(3))/9);
	obj->set("neili",me->query("max_neili")*(d+random(3))*3/18);	
	obj->set("combat_exp",me->query("combat_exp")*(d+random(3))/9);	
if((obj->query("combat_exp")-me->query("combat_exp"))>30000000)         obj->set("combat_exp",me->query("combat_exp")+30000000);
                //��ֹ����������������30M;
	obj->set("kill_object",me);
	obj->set("jiali",200);
	inv = all_inventory(obj);
	if(sizeof(inv))
	{
		for (k=0;k<sizeof(inv);k++) {
			if( !inv[k]->query("unique") )
				inv[k]->set("copy_object",1);
		}
	} 
	if(x>0)  obj->set("teamleader",1);//ͷͷ
	obj->set_name(obj->query("name"), ({ obj->query("id"),"mengdie npc"}));//Ϊ�˷�������
    obj->set("party",my_party["party"]);//Ϊ�˷������
	obj->move(environment(me)); 
}
void random_gift(object me)
{
        object obj;
        string str = "";
        int i = random(3);
	    int tt=me->query("quest/special/time");
		int x=me->query("quest/special/score");
		int y=me->query("quest/special/gift");
		int p=me->query_temp("quest/special/p");//���׳̶�
		int j=me->query_temp("quest/special/j");//������
		int a=me->query_temp("quest/special/a");//�߼� �ͼ��书
		int gg=0;
		int level=1;
		if(!p) p=1;
		if(!j) j=2;
		if(!a) a=0;
		if(!tt) tt=1;

		if(x<Gift_Limit) return;
		if(x<(y+1)*Gift_Limit) return;
		if(a==0 && !random(3)) return; //�ͼ��书��ý������ʵ�
		if(random(j+2)<3) return;//����Խ�ټ���Խ��
		if(random(p+2)<2) return;//�Ѷȿ��Ƽ���

        switch(i) {
                        case 0:         
                                obj = new (BOOK);
                                str = "��";  
                                break;
                        case 1: 
                                obj = new (MIC);
                                if (random(me->query_kar()) > 29) {
                                        obj->set("secret_obj",1);
                                        str = "��Ʒ";
                                }
                                str += "ҩ";     
                                break;
                        case 2:         
                                obj = new (MON);
                                str = "Ǯ"; 
                                break;
                        default:return;
		}
		if((random(150)<5+(p+j)/2||random(p+j)>17) && time()-tt>(60*60*12+random(60*60*6)))
			                     //�Ѷȿ��Ƹ߼�����,p���9
			                     //�������Ƹ߼�����,j���10
								 //ʱ��������12��Сʱ~18��Сʱ
								 //������Ѷ�9 ����10����� һ��������
		{
			i = random(4);
			if(!random(4)) level+=1;
			if(!random(8)) level+=1;
			if(!random(12)) level+=1;
			if(!random(24-p-j)) level+=1;//�ѶȺ��������ӽ����ȼ�
			destruct(obj);
			switch(i) {
		          case 0:
					  obj = new(DAZAO);
					  str = "������ʯ";
					  break;
				  case 1:
				  case 2:
				  case 3:
					  obj = new(JADE);
					  str = "��";
					  obj->set_level(level);
					  break;
				  default:return;              			
			}
            me->set("quest/special/time",time());
			gg=1;
		}	
        if (!objectp(obj))
        {
                CHANNEL_D->do_channel( this_object(), "sys",sprintf("%s����",str));
                return;
        }
        obj->set("gift_target",me->query("id"));
        obj->move(me);
        message_vision("$NͻȻ�����������ƺ����˺ܶ࣬��ͷһ����Ȼ��һ"+ obj->query("unit")+obj->name()+"��\n",me);    
		me->add("quest/special/gift",1);
      	CHANNEL_D->do_channel( this_object(), "rumor",sprintf("��˵%s�ڵ���¥�������һ%s��",me->query("name"),obj->query("unit") + obj->name()));
        if(gg==1) 
			log_file("quest/SPECIAL",sprintf("%s(%s)��%d�λ��%s�������ȼ���%d", me->name(1),me->query("id"),me->query("quest/special/gift"),obj->name(),level));
		else 
			log_file("quest/SPECIAL",sprintf("%s(%s)��%d�λ��%s������", me->name(1),me->query("id"),me->query("quest/special/gift"),obj->name()));
}
void destruct_person()
{  
	object *player,*obs,me;
	int i,k;
	player = all_inventory(this_object());
	for (i = 0; i < sizeof(player); i++) {
		if (!living(player[i])) continue;
		if (userp(player[i])) continue;
		if( player[i]->query("id")=="mengdie npc"|| player[i]->query("quest/level")) 
		{
			if(random(2)) command("wait");
			else if(random(2)) message_vision(HIG"\n$N����һ����������ʧ�ڽ����\n\n" NOR, player[i]);
			else message_vision(HIG"\n$N���������˳�ȥ��\n\n" NOR, player[i]);
			obs = deep_inventory(player[i]);       
			obs = filter_array(obs,(:$1->query("imbued"):));
			k = sizeof(obs);
			if(player[i]->query("kill_object") && player[i]->query("quest/level"))
			{
				me=player[i]->query("kill_object");
			}
			while(k--)
			{
				if(me) 
				{
					tell_object(me,HIY"ͻȻ������������ƺ����˵�ʲô����ͷһ����Ȼ�Ǹղ�ʧȥ����һ"+obs[k]->query("unit")+obs[k]->name()+HIY"��\n"NOR);
					obs[k]->move(me);
				}
				else 
				{
					message_vision(YEL"$N����һ"+obs[k]->query("unit")+obs[k]->name()+NOR+YEL"��\n"NOR,player[i]);
					obs[k]->move(environment(player[i]));
				}
			}
			destruct(player[i]);
		}
	}
}
