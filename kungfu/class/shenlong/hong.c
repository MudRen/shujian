//Cracked by Roath
// hong antong �鰲ͨ
// modified by ALN 10 / 97

#include <ansi.h>
#include <localtime.h>

inherit NPC;
// inherit F_MASTER;

int ask_jiao();
int ask_wan();
int ask_dan();
string ask_skill();

void create()
{
	set_name("�鰲ͨ", ({ "hong antong","hong", "jiaozhu" }));
//      set("nickname", "");
	set("long",
		"������ϣ����޴��أ����϶����˰����ƣ���ª֮����\n");
	set("gender", "����");
	set("age", 51);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 31);
	set("int", 32);
	set("con", 29);
	set("dex", 29);
	set("max_qi", 3500);
	set("max_jing", 3200);
	set("neili", 4000);
	set("max_neili", 4000);
	set("combat_exp", 3500000);
	set("jiali", 50);
	set("shen", -100000);

	set_skill("force", 400);
 	set_skill("dulong-dafa", 360);
	set_skill("dodge", 400);
	set_skill("lingshe-shenfa", 320);
	set_skill("strike", 400);
	set_skill("huagu-mianzhang", 360);
	set_skill("parry", 400);
	set_skill("medicine", 200);
	set_skill("yingxiong-sanzhao", 360);
	set_skill("literate", 160);
	set_skill("digging", 360);
	set_skill("kick", 240);
	set_skill("jueming-tui", 300);
	set_skill("finger", 280);

        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/dodge", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
//      map_skill("magic", "shenlong-magic");
	map_skill("finger", "yingxiong-sanzhao");

	prepare_skill("strike", "huagu-mianzhang");
	prepare_skill("kick", "jueming-tui");

	create_family("������", 1, "����");

	set("inquiry", ([
                "��̥�׽���" : (: ask_wan :),
                "����������" : (: ask_dan :),
		"������" : (: ask_jiao :),
                "��������" : (: ask_skill :),
                "skill" : (: ask_skill :),
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        ::init();

  //      add_action("do_flatter", "flatter");
}

int ask_wan()
{
        if( !this_player()->query("sg/spy") ) {
                command("consider " + this_player()->query("id"));
                return 1;
        }

        command("say ����֥�����£�Ҳ�õ������ң�");
        return 1;
}

int ask_jiao()
{
        if( !this_player()->query("sg/spy") ) {
                command("consider " + this_player()->query("id"));
                return 1;
        }

        command("say ���ڽ��е����£���ȥ����ͷ�ӡ�");
        return 1;
}

int ask_dan()
{
        object ob, me = this_player();

        if( !me->query("sg/spy") ) {
                command("consider " + ob->query("id"));
                return 1;
        }

        if( (int)me->query("sg/exp") < 100 ) {
                command("say ��ƾ���ڽ��еı��֣�Ҳ������Ҫ������������");
                return 1;
        }

        if( time() < (int)me->query("bmdan_time") + 1800 ) {
                command("say ��̫̰�ˣ���Ҫ������Ҫ����");
                return 1;
        }

        command("say �ðɣ���������������������͵㡣");
        ob = new(DRUG_D("bmdan"));
        ob->move(me);
        me->set("bmdan_time", time());
        message_vision("$N����$nһ" + ob->query("unit") + ob->name() + "��\n", this_object(), me);
        command("say �������Σ���Ĺ�ͷ���á�");
        return 1;
}

int do_flatter(string arg)
{
        object ob = this_player();

        if( !arg ) return notify_fail("��Ҫ˵ʲô��\n");

        if( arg != "hong"  && arg != "�鰲ͨ"
        &&  arg != "jiaozhu" && arg != "����" )
                return notify_fail("��Ҫ��˭��\n");

        if( !ob->query("sg/spy") ) {
                message_vision("$N�����޳ܵ�˵����ף���������һͳ�������󱻲���������\n", ob);
                command("haha");
                command("say �벻���Ϸ��ڽ����������ʢ����������������\n");
                return 1;
        }

        message_vision("$N�߾����֣��е�������������겻�ϣ������ɸ����������룡��\n", ob);
        command("nod");

        if( random((int)ob->query("kar")) > 9 
        && (int)ob->query("sg/exp") >= 100
        && ob->query("sgjob") ) {
                command("smile");
                ob->delete("sgjob");
                command("say �겻��һ�ν����㲻��ʲô���£��´�Ŭ���ɡ�\n");
        }

        if( time() > (int)ob->query_temp("flatter_time") + 900 ) {
                ob->add_temp("flatter_bonus", 1);
                ob->set_temp("flatter_time", time());
        }

        return 1;
}

string ask_skill()
{
        object me = this_player();

        if( me->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !me->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���";

        if( (int)me->query("sg/exp") < 5000 )
                return "��ƾ���ڽ��еı��֣�����ô�ܴ����㱾���ؼ���";

        if( (int)me->query_skill("huagu-mianzhang", 1) >= 30 )
                return "�㻹��ȥ��������ϰ�ɡ�";

        command("nod");
        me->set_skill("huagu-mianzhang", 30);

        message_vision(HIB"\n$N�Ļ������ƽ����ˣ�����\n\n", me);

        return "�ã����ڱ��̹����Ժգ��Ҿʹ������Ȿ���ؼ��ɡ�";
}
