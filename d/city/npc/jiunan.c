#include <job_mul.h>
#include <ansi.h>
#include <get_place.h>
inherit NPC;
int check(object ob);
string ask_job();
string ask_fail();
void create()
{
set_name("����ʦ̫", ({ "jiunan shitai", "jiunan" ,"shitai"}));
set("long",@LONG
�����ǳ����ʵ�����Ů����ƽ�����������싉�ƣ���Ϊ���еھŹ�С�����š�
���Գɹ����Ͻ��ǣ������������裬�ӽ���ɱ֮��һʧ�������һ�ۣ�����
���Ҵ�������ң����š����ѡ����;����񹦣���Ϊ���ֱ��𣬽�����
�ƶ������ᡣ
LONG
	);
	set("title", HIG "��������" NOR);
        set("gender", "Ů��");
        set("class", "bonze");
        set("age", 45);
        set("per", 24);
        set("str", 31);
        set("con", 30);
        set("dex", 30);
        set("int", 28);

        set("neili", 2400);
        set("max_neili", 2400);
        set("jiali", 30);
        set("max_qi",2000);
        set("max_jing",1200);
        set("combat_exp", 1200000);
        set("shen_type", 1);
        set("no_get","��������˵̫���ˡ�\n");
set("no_quest",1);
set("no_bark",1);
        set_skill("sword", 160);
        set_skill("force", 160);
        set_skill("parry", 160);
        set_skill("dodge", 160);
        set_skill("strike", 160);
set("chat_chance", 30);
set("chat_msg", ({
(: random_move :)
  }) );

set("inquiry", ([
               "������":        (: ask_job :),
		"job" :		(: ask_job :),
                "ʧ��" :	(: ask_fail :),
		"shibai":	(: ask_fail :),

]));

        setup();

        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/emei/obj/shoes")->wear();
        carry_object("/d/emei/obj/cloth")->wear();

}
string ask_job()
{
	object target, *living , me = this_player() , ob , beauty;
	int i,j;
	string str;
if( me->query("combat_exp") < 100000 )
		return "���ʵս����̫���ˣ�����ȥ�ҿ�ʵ�ڲ�����ģ�";
if( !(wizardp(me) && me->query("env/test")) && me->query("jn/qiuche") && ((time()-(int)me->query("jn/qiuche_time"))<(12*60)) )
		return "�Ҳ��ǽ��㵽"+me->query("jn/qiuche_place")+"ȥ��������ô��";
if( !(wizardp(me) && me->query("env/test")))
	if( me->query_condition("job_busy") || me->query_condition("jn_job")) {
		if ( me->query("job_name") == "������") {
		    command("shake "+(string)me->query("id"));
		    return "����ЪЪ�ɣ�";
		}
		else
		    return "�㻹������Ϣ��Ϣ�ɡ�";
	}
me->delete("jn/qiuche_busy");

	if(me->query("shen") < 0 && !wizardp(me)){
		return "�ҿ�����Ŀ���ɣ��ǲ������ӵļ�ϸ��";
	}
	if(me->query_temp("quest/busy")) //added by tangfeng ��quest��ͻ
		return "����������û�и���������㻹���ȴ����������������˵�ɡ�";

	living = livings();
	for (i=0;i < sizeof(living);i++){
		j = random(sizeof(living));
		if (j <= 1 || j == sizeof(living)-1) continue;
		if(check(living[j]) ){
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


	if( !target )
		return "�����û��˵��ʲô����־ʿҪ����ն�����һ��������ɡ�";

me->apply_condition("job_busy", 40);
	me->apply_condition("jn_job", 40);
	me->set("jn/times", uptime());
	me->set("jn/qiuche",1);
	me->set("jn/qiuche_time",time());
	me->set("jn/qiuche_place",get_place(base_name(environment(target)))+environment(target)->query("short"));

	beauty = new("/quest/jqc/qc");
        beauty->set("guard", me->query("id"));

	beauty->set("long", beauty->query("long")+
		"�������Ǿ���ʦ̫Ҫ��"+me->query("name")+"("+capitalize(me->query("id"))+")Ҫ�ٵ�������\n");
	beauty->move(environment(target));
	

if(wizardp(me)) tell_object(me, base_name(environment(target))+"\n");
		command("nod");
	command("whisper " + me->query("id")+ " ��˵���"+me->query("jn/qiuche_place")+GRN"����Ҫ·��һ������������Ѻ����һ��������ն�ķ���־ʿ��");

	return "����ҽ�������ǧ��С�ġ�";
}
string ask_fail()
{
	object me = this_player();
	int i;

	if( !me->query("jn/qiuche") )
		return "�������û����ʧ��ʲôѽ��";

	command("ok "+me->query("id"));

	me->delete("jn/qiuche");
	me->delete("jn/qiuche_time");
	me->delete("jn/qiuche_ob");
	me->delete("jn/qiuche_super");
me->delete_temp("jn/jie");
me->delete_temp("jn/bb");
me->delete("jn/time");
		
	i = 40 - me->query_condition("jn_job");
	if ( i >= 9 )
		me->apply_condition("job_busy", 1);
	else
		me->apply_condition("job_busy", 9 - i);

	me->apply_condition("jn_job", 10);

me->apply_condition("jn_job",40);
		me->delete("jn/qiuche_place");
	return "û��ϵ�������ľ����ˣ��´ΰ��Ұɡ�";
}
void kill_ob(object ob)
{
        ob->remove_killer(this_object());
        remove_killer(ob);
        message_vision("����ʦ̫����ҡ��ҡͷ��һ˫���������峺��\n", ob);
        message_vision("�����룬�����ܶ���λ��ʦ̫���֣�δ��̫�����ˡ�\n", ob);
}

void unconcious()
{
        say( "����ʦ̫������ţ�˲���ָֻ��˾���\n");
        reincarnate();
        set("eff_qi", query("max_qi"));
        set("qi", query("max_qi"));
        set("eff_jing", query("max_jing"));
        set("jing", query("max_jing"));
        set("jingli", query("eff_jingli"));
}

void die()
{
        unconcious();
}












int check(object ob)
{
	object room;
	string room_name;

	if(!objectp(ob)
	 || !ob->query("startroom")      // add by Yuj@SJ to void job NPC
	 
	 || userp(ob)
	 
	 || !objectp(room=environment(ob))
	 || room->query("no_fight")
	 || room->query("quest")
	 || room->query("outdoors") == "���ش��"
	 || strsrch(room_name = file_name(room),"/d/") != 0
	 || strsrch(room_name, "/d/wizard/") == 0
	 || strsrch(room_name, "/d/wuguan/") == 0
	 || strsrch(room_name, "/d/group/") == 0
	 || strsrch(room_name, "/d/death/") == 0
	 || strsrch(room_name, "/d/mingjiao/lsd/") == 0
	 || strsrch(room_name, "/d/mingjiao/bhd/") == 0
	 || strsrch(room_name, "/d/xueshan/") == 0
	 || strsrch(room_name, "/d/shaolin/fumoquan") == 0
	 || strsrch(room_name, "/d/baituo/") == 0)
	 return 0;
	return 1;
}



