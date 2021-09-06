// taohong.c

inherit NPC;
#include <ansi.h>
#include "/d/suzhou/npc/lchj.h";
void outwuguan(object me);
string ask_qiqiang();
string ask_gaotou();
void create()
{
	set_name("������", ({ "zhongnian qifu","qifu","zhongnian" }) ); 
	set("gender", "Ů��" );
	set("age", 33);
	set("long", "һ�������򸾣���ͷ��������ͷɢ�����·��ۻ����á�\n"); 
	set("combat_exp", 1000);
 
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"�������૵ص�����ү���ϼ���Ҫ��ǽ����ô�ֵ��ң���....�ֲ�����Ϲ˵��\n",
		"�����򸾾�����֣����������ʲô�ط������ϵã����ҵ�����ȥ��\n",
		"�����򸾵�����ү�ֲ��ǲ��ţ�����...����....����û˵����үȴ�����ҳ�����\n",	 
	}));
	set("inquiry", ([
		"����" : "�Ҳ���ʶ��������Ĳ���ʶ����",	
		"�ݳ���" :  "�Ҳ���ʶ��������Ĳ���ʶ����",	
		"��ǽ" : (:ask_qiqiang:),  
		"��ͷ" : (:ask_gaotou:),  
	]));
	carry_object(ARMOR_D("cloth"))->wear();
}
string ask_qiqiang()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query(QUESTDIR1+"over") || !me->query_temp(QUESTDIR2+"start" ))
	{
	   call_out("outwuguan",1,me);
	   return "����ô��������ģ�";
	}
	if(me->query_temp(QUESTDIR2+"askqiqiang" ))
	{
	   command("say");
	   return "�����....��Ĳ���Ϲ˵��";
	}
	command("look "+me->query("id"));
	message_vision(HIY"$N����¶���־����ɫ��\n", ob);
	command("say ��ү���ϼ������Ÿ�ͷ��Ҫ��ǽ����ô�ֵ��ң�");
	command("say ����϶�����ү�����������ˣ�����ɱ������ͷ�������ݺ���ʲô�ơ�");
	command("fear");
	me->set_temp(QUESTDIR2+"askqiqiang",1);
	return "";
}
string ask_gaotou()
{
	command("look "+this_player()->query("id"));
	command("say �⿲����Ӧ���аɡ�");
	return "";
}
void outwuguan(object me)
{
	object ob=this_object();
	object *inv;
	if(!me) return;
	command("?");
	message_vision(HIY"$N����¶���ɻ����ɫ��\n", ob);
	command("say ����ô��������ģ�");
	message_vision(HIR"ֻ����һ�����˰���$N��һ������������ˡ�\n"NOR, me);
	me->delete("enter_wuguan");
	inv = filter_array(deep_inventory(me), (: userp :));
	if( sizeof(inv))
		inv->move(environment(ob));
	me->unconcious();
	me->move("/d/xiangyang/damen");
	me->delete_temp("quest/busy");//
	me->delete_temp("quest/���Ǿ�");
}
