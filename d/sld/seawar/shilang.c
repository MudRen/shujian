// ʩ��
// 1/28/2002	by augx@sj
//update by jpei 2010 ���˺�ս�Ľ���


inherit NPC;
#include "ansi.h"
#define	SEAWAR_D	__DIR__"seaward"

string ask_seawar();
int ask_xuexi(object who);

void create()
{
	set_name("ʩ��", ({ "shi lang", "shi" }));
	set("title", "������������");
	set("shen_type", 1);

	set("gender", "����");
	set("age", 35);
	set("long", "���˾�����������������һ���佫����������ݡ�\n����׼��������崬�ӹ�����������");

	set_skill("sword", 120);
	set_skill("cuff", 120);
	set_skill("dodge", 120);
	set_skill("taizu-quan", 120);
	set_skill("xiaoyaoyou", 120);
	set_skill("force", 120);
	set_skill("huntian-qigong", 120);
	set_skill("parry", 120);
	set_skill("literate", 100);
	
	map_skill("cuff", "taizu-quan");
	map_skill("parry", "taizu-quan");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("force", "huntian-qigong");
	prepare_skill("cuff", "taizu-quan");

	set_temp("apply/damage", 50);

	set("combat_exp", 300000);
	set("attitude", "friendly");
	
	set("no_ansuan",1);
	set("no_bark",1);
	set("no_quest",1);
	set("no_get", 1);
	set("job_npc", 1);

	set("inquiry", ([
		"����������" :	(: ask_seawar() :),
		"job" :		(: ask_seawar() :),
		"��ս" :	(: ask_seawar() :),
		"������" :	"������Ҫ�����������������Ը���ս�Ϳ����Ӿ��ɣ�",
                            "ı��":                    (: ask_xuexi :),
                           "��սָʾ":                    (: ask_xuexi :),
	]) );
	
	set("chat_chance", 2);
	set("chat_msg", ({
		CYN"ʩ��˵������������ǿ��׳�����öԸ�����\n"NOR,
		CYN"ʩ��˵������˵����������ɲ���������˼����ڴ�����֪�����Ǽ١�\n"NOR,
		CYN"ʩ��˵�����л��ϵ��������ӣ���ս��ʤ��\n"NOR,
	}) );
	
	setup();
	carry_object(ARMOR_D("armor"))->wear();
	carry_object(BINGQI_D("sword"))->wield();
}

void kill_ob(object ob)
{
	object me = this_object();
	command("say ���������ڼ���û���������档");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say ���������ڼ���û���������档");
	return 0;
}

string ask_seawar()
{
	object * team;
	object me;
	int i;
	
	me = this_player();
	team = me->query_team();


	if(wizardp(me) && me->query("env/test"))
		return SEAWAR_D->play(me,me,1);
	
	if( sizeof(team) != 2 )
		return "������ս����Ķ������Ҫ�������ˡ�";
	for (i=0;i<sizeof(team);i++) {
		if ( !team[i] || !userp(team[i]) || !present(team[i],environment(me)) )
			return "��Ҫ��˭һ���ս��";
		if( team[i]->query_condition("job_busy") || team[i]->query("job_name")=="��������ս" || team[i]->query_condition("killer") )
			return "���ǵĶ���̫æµ�ˣ���Ϣһ����ٲ�ս�ɡ�";
		if( team[i]->query("combat_exp")<100000 )
			return "���ǵĶ���ľ���̫���ˣ�������ȥ����һ�¶�������ս�ɡ�";
		if( team[i]->query("shen")<30000 )
			return "�����ƺ����Ǻ����������ҿɲ����������ǲ�ս��";
		if( team[i]->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
			return "���������ڽ���֮�У����ǻ����ȴ����������������˵�ɡ�";

	}

	return SEAWAR_D->play(team[0],team[1],1);
}

int ask_xuexi(object who)
{
object me = this_player();
        object obj;
        int i, g,s,times;
        i = random(2);
       g= me->query_skill("gunnery",1);
       s=me->query_skill("sailing",1);
       times = (int)me->query("job_time/�������ս",1);

        if ( times<100 || times < (int)me->query("hz_times") +50  ){
		command("say ֽ��̸����û���õģ����μӼ��κ�ս�������Ұɣ�\n");
		return 1;
	}
        if ( g >500 && s >500 ){
		command("say ����������Ȼ�����Ϸ�֮�£�һ�о���������˼���±��ǡ�\n");
		command("flatter " + me->query("id"));
		return 1;
        }

if( times >= (int)me->query("hz_times") +50 ) 
         {
                 command("praise " + me->query("id"));
       message_vision("say �������ո��뵽һЩ�о�����֮��������ȥ��ϸ����һ�£��Ա���ս֮�á�\n",me);
	
                 me->set("hz_times",times);

               switch(i) {
                        case 0:         
                                obj = new ("/d/sld/seawar/gunnery-book");
                                obj->set("max_skill", g+ 10);
                                break;    
                         case 1:         
                                 obj = new ("/d/sld/seawar/sailing-book");
                                obj->set("max_skill", s+ 10);
               
                                break;   

                                break;  
                        default:return 1;
                           }
                   if( me->query_skill("sailing") > 500 ) { 
                                obj = new ("/d/sld/seawar/gunnery-book");
                                obj->set("max_skill", g + 10);
                                                                                  }
                           if( me->query_skill("gunnery") > 500 ) { 
                                obj = new ("/d/sld/seawar/sailing-book");
                                obj->set("max_skill", s + 10);
                                                                                  }
                           obj->move(me);

              message_vision(HIC"ʩ���ó�һ��������ս�ʼǽ�����$N��\n"NOR, me);  
	return 1;
	}

       command("say ���������ڼ������ҹ�����������\n");

        return 1;
}



