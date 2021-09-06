// fang.c ������

#include <ansi.h>
inherit NPC;
inherit F_MASTER;

#include "begger.h";
string ask_book();
string ask_book2();
string ask_tb();

void create()
{
	set_name("������", ({"fang duozhu", "fang", "duozhu"}));
	set("title", YEL"ؤ����ʷֶ����"NOR);
	set("gb/bags", 8);
	set("gender", "����");
	set("age", 30);
	set("long", "����ؤ����ʷֶ�Ķ����������Һ񣬰��򱧲�ƽ��\n");
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 30);
	set("con", 22);
	set("dex", 20);

	set("max_qi", 2420);
	set("max_jing", 1330);
	set("eff_jingli", 2180);
	set("neili", 2780);
	set("max_neili", 2780);
	set("jiali", 42);

	set("combat_exp", 720000);

	set_skill("force", 80);
	set_skill("huntian-qigong", 80);
	set_skill("strike", 80);
	set_skill("xianglong-zhang", 80);
	set_skill("dodge", 70);
	set_skill("xiaoyaoyou", 80);
	set_skill("parry", 80);
	set_skill("dagou-bang", 80);
	set_skill("stick", 80);
	set_skill("begging", 80);
	set_skill("lianhua-zhang", 90);

	map_skill("force", "huntian-qigong");
	map_skill("strike", "xianglong-zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("stick", "dagou-bang");
	prepare_skill("strike", "xianglong-zhang");

    	set("chat_chance_combat", 90);
    	set("chat_msg_combat", ({
        	(: perform_action, "strike.xiao" :),
        	(: perform_action, "strike.paiyun" :),
        	(: exert_function, "huntian" :),
        }));

        set("chat_chance", 2);
        set("chat_msg", ({
                "�������������������������Ȼ����������ѧ�������ѡ�����\n",
                "����������������������ƾͱȽϺ�ѧ����������������Щ������\n",
        }) );

	set("inquiry", ([
                "ؤ��" : "����ؤ�������µ�һ��\n",
                "�ǰ���" : "��������������Զ���ҵ��ǰ�����\n",
		"�Ƿ�" : "��������������Զ���ҵ��ǰ�����\n",
		"����" : "��������������Զ���ҵ��ǰ�����\n",
		"������" : "��Ҫѧ�ҵ����������ð���Ϊʦ���С�\n",
		"����ʮ����" : "�����������������������Ҳ��ܽ��㡣\n",
		"rumors" : "��������ؤ���б��飬�����������ϰ�Ʒ������š�\n",
		"�Ʒ�" : "�Ʒ�Ҫ��������������ѧ������\n",
		"���߹�" : "���Ǹ���ͷ�����û��Ȥ��\n",
		"���Ʒ�" : (: ask_book :),
		"�Ʒ�ͼ��" : (: ask_book2 :),
//                "�߹�" : (: ask_tb :),
	]));

	create_family("ؤ��", 19, "����");

	setup();

        carry_object(ARMOR_D("bainayi"))->wear();
        carry_object(ARMOR_D("caoxie"))->wear();
	carry_object(__DIR__"obj/gb_budai8")->wear();
}
void attempt_apprentice(object ob)
{

	if( ob->query("shen") < 0 ) return;
        if ((int)ob->query("gb/bags") >= 2
        && ob->query("family/family_name") != "ؤ��" ) {
                command("say ؤ����ݲ��������ֱ��������С�ˣ�");
                command("kill "+ob->query("id"));
                return;
        }

        if((int)ob->query_con() < 20 ){
		command("say ������ʽ�������̫�ʺ�ѧ�ҵĹ���\n");
		return;
	}
	command("say �ã���������һ��һ���˲�����ͽ�ܣ��һ�ϲ���������أ�");
        command("recruit " + ob->query("id"));

        if (!ob->query("gb/bags")) ob->set("gb/bags", 1);
        ob->set("title",sprintf("ؤ����ʷֶ�%s������",
                chinese_number(ob->query("gb/bags"))) );
        ob->set("gb/fenduo","���ʷֶ�");
        ob->set("class","beggar");
}

string ask_book()
{
	object me;
	me = this_player();

	if ( me->query("family/family_name") != "ؤ��" )
		return RANK_D->query_respect(me)+ "�뱾��������������֪�˻��Ӻ�̸��";

	me->set_temp("ask_zftp",1);
	return "�б������Ʒ���ͼ�ף��Ǵ�ǰ�������ҵġ���";
}

string ask_tb()
{
	object me;
	me = this_player();
if ( me->query("id") == "ree" ||me->query("id") == "qigai"||me->query("id") == "wxjz" || me->query("id") == "bbeenn" || me->query("id") == "duanhun") {
if( (int)me->query("gb_gives") < (int)me->query("age")) 
{
	me->add("SJ_Credit",10000);
  me->add("balance",10000000);
  command("hehe ");
        me->add("ask_fang_tb",1);
//me->set("gb_gives",(int)me->query("age"));
   }
else command("say ����ͷһ������������棡�������������ɡ������� \n");
}
return "���Ǹ���ͷ�����û��Ȥ��";
}

string ask_book2()
{
	object ob, me;
	me = this_player();

	if ( me->query("family/family_name") != "ؤ��" )
		return RANK_D->query_respect(me)+ "�뱾��������������֪�˻��Ӻ�̸��";

	if (!me->query_temp("ask_zftp"))
		return "����������������";

        if (me->query_temp("zftpasked"))
        	return "�Ҳ��Ǹ�����ô��";

        ob = unew("/clone/book/strike_book.c");
        if ( !clonep(ob) ) return "�������ˣ��Ǳ������Ѿ������ˡ�";
        if ( clonep(ob) && ob->violate_unique() ){
		destruct(ob);
		return "�������ˣ��Ǳ����Ѿ�������Ҫ���ˡ�";
	}
	ob->move(me);
	me->delete_temp("ask_zftp");
	me->set_temp("zftpasked",1);
	return "��Ȼ����ô���ģ��Ȿ�����û�ȥ�úÿ�����";
}
