//add by tangfeng
//2005.3
#include <ansi.h>
inherit ROOM;
string look_ziji();
string look_paizi();
int do_dream(string arg);
void must_dream(object me);
void check(object me,object ob);
int sort_user(object ob1, object ob2);
#define Score_Limit 1000
#include "/d/city/diemenglou_poison.h";
#include "/d/city/diemenglou.h";
void create()
{
	set("short",HIW"����¥һ¥"NOR);
	set("long","һ��СС�ĸ�¥������Ϊ�꣬��Ϊ�ǣ�����Ϊ������Ϊ·�����ϼ�����
��ȥ�е����ҵĲ�ϯ������һ�Ⱥڶ�����С���ţ�����ǽ�����������ָ�����
Ŀ��"+HIR"����"NOR+"�������滹��һ���ּ���"+HIC"ziji"NOR+"������ֻ������ʰ�쵣���¥��֮���
����ȥ���Ա�����һ��ľ�̵����ӣ�"+HIY"paizi"NOR+"�����ƺ�������ʲô��
");
	set("exits",([
		"up" : __DIR__"diemenglou2",
	]));
	set("item_desc",([            
            "ziji" : (: look_ziji :),
            "paizi" : (: look_paizi :),
        ]));
	set("quest",1);
	set("no_death",1);
	set("no_get_from", 1); 
	set("no_sleep_room", 1);
	set("outdoors", "����");
	set("coor/x",80);
	set("coor/y",40);
	set("coor/z",0);
	setup();
}
void init()
{
	object me;
	me = this_player();
	if(userp(me) && !wizardp(me)&& (me->query_condition("killer")||me->query_condition("job_busy")|| !me->query_temp("quest/special/up")))
	{
		me->remove_all_killer();
		me->revive();
		me->reincarnate();
		message_vision(HIC"\nͻȻ$N��ǰһ�����ܱߵ�һ��������á�$N�����մ����졣\n"NOR,me); 
		me->move("/d/city/lxs");
		me->start_busy(2);
		return;
	}
	add_action("do_dream", ({"dream"}));
	add_action("do_liaoshang", ({"liaoshang"}));
	add_action("do_chakan", ({"chakan"}));
	add_action("do_action", ({"dazuo", "tuna", "lian", "learn", "du", "steal", "hit",
                                  "kill", "fight", "study", "practice", "exercise", "halt", "ask","whisper",
	                          "quit", "save", "throw", "suicide"}));
	if(me->query_temp("quest/special/up"))
	{
		remove_call_out("must_dream");
		call_out("must_dream",120,me);
	}
}
void must_dream(object me)
{
	if(!me) return;
	if(!me->query_temp("quest/special/up") || !me->is_fighting())
	{
		me->remove_all_killer();
		me->reincarnate();
		message_vision(HIC"\nͻȻ$N��ǰһ�����ܱߵ�һ��������á�$N�����մ����졣\n"NOR,me); 
		message_vision(HIY"$Nֻ����һ�����ʣ���Ȼ�ƺ���ƮƮȻ���뿪���Ǹ�С¥��\n"NOR, me);
		me->move("/d/city/lxs");
           me->set("quest/special/up/time",time());
		message_vision("$N����ææ��������"+environment(me)->query("short")+"��\n", me);
		tell_object(me,HIY"�㻳���Լ�Ҳ�������û�е���һ�������ε�¥�ĵط���\n�ε�¥�����⣬���㣬����ãã���齣�����С���\n"NOR);
        me->start_busy(2);
		me->delete_temp("quest/special");
		remove_call_out("again_check");
		call_out("again_check",3,me);//Ϊ�˷�ֹdazhuan ���Ƶ�pfm ���ֱ������������bug
		return;
	}
}
int do_action(string arg)
{
	if(!wizardp(this_player())){
		write("�ε�¥��ֻ�ܱ��䣬�벻Ҫ������ص��£�\n");
		return 1;
	}
	else return 0;
}

string look_ziji()
{
    	object me;
		string str;
    	me = this_player();
		if(me->is_fighting()) 
			return "����æ���ء�\n";
    	if (me->is_busy()) 
          	return "����æ���ء�\n";
    	me->start_busy(2);
		    str  = HIR"\n               �һ������α��飬��Я�齣�����ġ�\n"NOR;

			str += HIC"\n��ң�ӻ���С������̾���������ʵ�������ƻá����ξ�ʱ���������㣬\n"NOR;
			str += HIC"����С��������һ�������������Σ�����֪��С�ӱ���������ʶ��֪��ζ��\n"NOR;
			str += HIW"\n�����������ʹ��dreamָ�����鹹�����ｻ�֣��ݻ����������齣������\n"NOR;
			str += HIW"����ѧ��Ŀǰ���ŵ�ָ���ʽ�У�\n"NOR;
			str += HIY"\ndream player |<id>|"NOR+"��"+HIM"����Ϸ��ָ��id��ҿ�ʼս��\n"NOR;
			str += HIY"dream npc |<���ɱ��>|<�Ѷȼ���>|<�����Ƿ�>|"NOR+"��"+HIM"��ָ������NPC��ʼս��\n"NOR;
			str += RED"\n���ɱ��Ϊ��\n"NOR;
		    str += WHT"1--�䵱 2--��ɽ 3--��ɽ 4--��Ĺ 5--ؤ�� 6--���� 7--������ 8--Ľ��\n"NOR;
			str += WHT"9--������ 10--���� 11--���� 12--���� 13--�һ��� 14--���� 15--����\n"NOR;
			str += WHT"16--���� 17--������ȫ 18--��󡹦 19--��а�� 20--���߽�\n"NOR;
			str += HBRED"\n�Ѷȼ����趨��1��9�������趨Ϊ1������Ϊ2�����Ϊ3������ȴ����Ϊ4��\n"NOR;
        tell_object(me,str);
    	return "";
}
string look_paizi()
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
int do_dream(string arg)
{
	string *str_menpai = ({ "wd","hs","ss","gm","gb","tz","dls","mr",
							"sld","xx",	"em","mj","thd","tls","sl","kl","9y","hmg","pxj","jsj"});
	object me = this_player();
	object obj,player,*inv;
	string player_id,player_party;
	int i,p,j,k;
	int a=1,b=0,c=100,d=9,e=0,f=0;
	// a  �߼�/�ͼ��书 b ����/���� c pfm���� d ����ӳ� e hubo f lbwb
	if(me->query_temp("killer")) return 0;
	if(!me->query_temp("quest/special/up")) return 0;//tjf������
    if(me->is_fighting()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
    if(me->is_busy()) 
        return notify_fail(RED"����æ���ء�\n"NOR);
    if((int)me->query_temp("quest/special/score")>99) 
        return notify_fail(RED"����"HIW"����¥һ��"RED"��ս��̫��Ķ��֣��ƺ��е�ƣ�ͣ��������û�����Ϣһ�°ɡ�\n"NOR);
	if(!arg) return notify_fail(HIR"ָ���ʽ��dream npc |����|����|����|����dream player |id|��\n"NOR);

	if(sscanf(arg, "npc |%d|%d|%d|", i, p,j) == 3
		|| sscanf(arg, "player |%s|", player_id) == 1);
	else return notify_fail(HIR"ָ���ʽ��dream npc |����|����|����|����dream player |id|��\n"NOR);

	remove_call_out("must_dream");
	if (sscanf(arg, "npc |%d|%d|%d|", i, p,j) == 3)
	{
		if(i>20 || i<1 || p>9 || p<1 ||j<1 || j>4) 
			return notify_fail(HIY"ָ��������ȡֵ��Χ����ϸ�Ķ��ּ��ϵ���ʾ��\n"NOR);
		
		if(j==2) b=1;
		else if(j==3) b=random(2);//�����ĸ���
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
			d=9+p-2;//����11%exp
			e=random(2);//����hubo
		}
		else if(p==4)
		{
			c=(p-2)*30+random((p-2)*30);
			d=9+p-3+random(p);//����11%~44%exp
			e=random(2);//����hubo
		}
		else if(p==5)
		{
			d=9+p-1+random(p-4);//����44%~66%exp
			e=1;//����hubo
			f=random(2);
		}
		else if(p==6)
		{
			d=9+p+random(p-3);//����66%~88%exp
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

		player_party=str_menpai[i-1];
		obj=new(__DIR__"npc/mengdie_npc1");
		obj->set("quest/level",p);//
		obj->copy_menpai(({player_party}),a,b,c);
		obj->set_skills_level((me->query("max_pot")-100)*d/9);	
		obj->copy_state();	
		obj->get_npc_name();	
		if(i<=16)
			obj->set("title",HIW+obj->query("family/family_name")+HIW"����"NOR);
		else obj->set("title",HIY+obj->query("family/family_name")+NOR);
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
		obj->set("combat_exp",me->query("combat_exp")*(d+random(2))/9);	
if((obj->query("combat_exp")-me->query("combat_exp"))>30000000)		obj->set("combat_exp",me->query("combat_exp")+30000000);
		//��ֹ����������������30M;
		obj->set("party_id",i);//���ɺ���
	}
	else
	{
        player=LOGIN_D->find_body(player_id);
		if(!player) player = find_living(player_id);
		if(!player)
			return notify_fail(HIY"û�з���һ��id��"+player_id+"����ҡ���ע����������б�\n"NOR);
		if(player==me)
			return notify_fail(HIY"���ṩ�Բ���������\n"NOR);
		if( wiz_level(me) < wiz_level(player) )
			return notify_fail("��û��ֱ�Ӻ����������ĸ���Ȩ����\n");
		if(wizardp(player))
			return notify_fail(HIY"��ʦ�޷�Ѱ�ң�\n"NOR);
		obj=new(__DIR__"npc/mengdie_npc1");
		obj->do_copy(player);
		obj->set("title",HIY"����Ʒ"NOR);
		if(!random(4))
		{
			obj->set("double_attack",1);
			obj->set_temp("double_attack",1);
			obj->set("title",HIR"����ͻ�临��Ʒ"NOR);
			obj->add("combat_exp",random(obj->query("combat_exp")));
			obj->add("max_qi",random(obj->query("max_qi")*3/2));
			obj->add("max_neili",random(obj->query("max_neili")/2));
			obj->reincarnate();
			obj->set("neili",obj->query("max_neili")*2);
		}
		i=obj->query("combat_exp")/me->query("combat_exp");
		if(i>0)
			obj->set("quest/level",i*i);//
	}
    if(!obj)
		return notify_fail(RED"�������ƺ�ʧЧ��\n"NOR);
	obj->set("jiali",200);
	obj->set("kill_object",me);
	message_vision(HIG"\nһ��������ܱ߾�ɫȫ�䣬$N�ɻ����ƺ�������ʷ��衣\nͻȻ�䣬һ��"+obj->short(1)+HIG"���˽�����\n"NOR,me,obj);
	obj->move(environment(me)); 
	obj->kill_ob(me);
	me->kill_ob(obj);
	inv = all_inventory(obj);
	if(sizeof(inv))
	{
		for (k=0;k<sizeof(inv);k++)
		{
			if( !inv[k]->query("unique") )
				inv[k]->set("copy_object",1);          
		} 
	}
	remove_call_out("check");
    call_out("check",1,me,obj);
	return 1;

}

void check(object me,object ob)
{
	object *obj,*obs;
	int i,x=0;

	if(!me || !living(me)||!present(me,this_object())||me->query("qi")<=1||me->query("jing")<=1||!me->query_temp("quest/special"))  
	{
		remove_call_out("check");
		remove_call_out("must_dream");
		if(ob)
		{
			obs = deep_inventory(ob);       
			obs = filter_array(obs,(:$1->query("imbued"):));
			i = sizeof(obs);
			message_vision(HIY"\nͻȻһ���ɢ��$Nԭ��վ�ŵĵط���Ȼһ��ۼ�Ҳû�����¡�\n"HIM"�ղŵ�һ�����λð㣬ȫȻ�����ڷ��С�\n"NOR,ob);
			while(i--)
			{
				if(me) 
				{
					tell_object(me,HIY"ͻȻ������������ƺ����˵�ʲô����ͷһ����Ȼ�Ǹղ�ʧȥ����һ"+obs[i]->query("unit")+obs[i]->name()+HIY"��\n"NOR);
					obs[i]->move(me);
				}
				else 
				{
					message_vision(YEL"$N����һ"+obs[i]->query("unit")+obs[i]->name()+NOR+YEL"��\n"NOR,ob);
					obs[i]->move(environment(ob));
				}
			}
			destruct(ob);
		}
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
	if (!ob || !present(ob,this_object()))  
	{
		remove_call_out("check");
		if(me)
		{
			me->remove_all_killer();
			destruct_poison(me);//ȥ��
			message_vision(HIW"\n����һ�����������$N��$N�������в��ָֻ���\n"NOR, me);
                   me->add("neili",(int)me->query("max_neili")/4+random((int)me->query("max_neili")/4));//���������ָ�����ǰ��/2  By lsxk 2007/7/2
			if(me->query("neili")>me->query("max_neili")*2) me->set("neili",me->query("max_neili")*2);
			remove_call_out("must_dream");
			call_out("must_dream",60,me);
		}
    	return;
	}
	call_out("check",1,me,ob);
}

int valid_leave(object me, string dir)
{
	int i=me->query("quest/special/score");
//   int p=me->query("quest/special/second_floor")
	if (me->is_fighting())
		return notify_fail(RED"\nս���У��㾹Ȼ�޷�����\n"NOR);
	if (present("mengdie npc",this_object()))
		return notify_fail(RED"\n�㻹�����С�\n"NOR);
	if(i<Score_Limit)
		return notify_fail(CYN"ͻȻ��Υ����������������������ǰ������λ"+RANK_D->query_respect(me) +"�����ս��������¥�����Ƕ��Ŭ���ɣ�\n"NOR);
/*  By lsxk �޸�ÿ���϶�¥��50�ֻ��֡�
	if (i<(p+1)*Score_Limit)
		return notify_fail(CYN"ͻȻ��Υ����������������������ǰ������λ"+RANK_D->query_respect(me) +"����Ȼ���Ѿ��ϴι�"+chinese_number(p)+"�Σ����ǻ�����ҪŬ�����еģ�\n"NOR);
*/
	 message_vision(HIY"\nͻȻ��Υ�������������������˹�����\n"NOR, me);
	 message_vision(CYN"���ͳ���$N΢Ц�ص��˵�ͷ��\n"NOR, me);
	 message_vision("����˵������"NOR+HIR"��λ"+RANK_D->query_respect(me) +"���벻������˽��˵�ս������ӭ������¥��"NOR+"��\n"NOR, me);
	 message_vision(WHT"���ţ����ͽ���һָ��ͻȻһ�����������$N��\n$N�ľ����������������д���Ȼָ���\n"NOR, me);
	 message_vision(CYN"������$N���˻��֣�\n"NOR, me);
	 remove_call_out("must_dream");
	 me->clear_condition();//
	 me->reincarnate();
	 me->add("neili",me->query("max_neili")/2+random(me->query("max_neili")/2));
	 me->add("quest/special/second_floor",1);
	 me->set_temp("quest/special/second_floor",1);
    me->add("quest/special/score",-50);
     return ::valid_leave(me, dir);
}

