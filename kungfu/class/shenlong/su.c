//Cracked by Roath
// su quan ����

#include <ansi.h>
inherit NPC;
//inherit F_MASTER;

int do_song(string);
//int do_bai();
string ask_wan();
string ask_miji1();

void create()
{
	set_name("����", ({ "su quan","su", "furen" }));
	set("title", "�����̽�������");
	set("long",
		"��ò�ٸ�����ģ��������ʮ��������ͣ�΢΢һЦ����̬�����������ޱȡ�\n");
	set("gender", "Ů��");
	set("age", 23);
	set("attitude", "peaceful");
	set("shen_type", -1);

	set("str", 23);
	set("int", 28);
	set("con", 24);
	set("dex", 24);
	set("max_qi", 800);
	set("max_jing", 600);
	set("neili", 800);
	set("max_neili", 800);
	set("jiali", 20);
	set("combat_exp", 50000);
	set("score", 5000);
	set("shen", -8000);

	set_skill("force", 50);
	set_skill("dulong-dafa", 50);
	set_skill("dodge", 55);
	set_skill("lingshe-shenfa", 55);
 	set_skill("strike", 54);
        set_skill("huagu-mianzhang", 80);
	set_skill("parry", 56);
	set_skill("sword", 58);
	set_skill("meiren-sanzhao", 65);
	set_skill("kick", 55);
	set_skill("jueming-tui", 55);
	set_skill("literate", 80);
	set_skill("medicine", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
        map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "meiren-sanzhao");
	map_skill("sword", "meiren-sanzhao");
	map_skill("kick", "jueming-tui");

	prepare_skill("kick", "jueming-tui");

        create_family("������", 3, "����");

        set("chat_chance", 5);
        set("chat_msg", ({
                "�������ĵ�˵��������ȥ���͸��ҵ��Ǹ���������֪Ū�Ķ�ȥ�ˡ�\n",
        }) );

	set("inquiry", ([
	//	"������" : (: ask_wan :),
	//	"�����ؼ�" : (: ask_miji1 :),
	]));

	setup();

	carry_object("/clone/weapon/duanjian")->wield();
	carry_object("/d/city/obj/pink_cloth")->wear();
	carry_object("/d/city/obj/flower_shoe")->wear();
}

void init()
{
        add_action("do_learn", "learn");
        add_action("do_learn", "xue");
}

int accept_object(object who, object ob)
{
        int sg_exp;
        string chname = "", name;

        if( !who->query("sg/spy") ) {
                command("consider " + who->query("id"));
                return notify_fail("������ŭ������Ҫ��������˭Ҫ���ֺ��ң���\n");
        }

        name = ob->name();
        for(int i = 0; i < strlen(name); i++)
                if(name[i] > 160 && name[i] < 255) chname += name[i..i];

        if( chname != "������" ) {
                command("sigh " + who->query("id"));
                return notify_fail("�������ĵ�˵��������ô�Ͳ����ҵ��ģ�\n");
        }

        if( (int)query("amount") > 3 )
                return notify_fail("����̾����,˵������л�������������Ѿ��кö��ˡ�\n");

        command("say ��л��λ"+ RANK_D->query_respect(who) + "�ˣ��Һ�ϲ��Ү��");
        add("amount", 1);
        call_out("destroy", 1, ob);

        if( (sg_exp = (int)who->query("sg/exp")) < 100 )
                who->add("sg/exp", 1);

        if( who->query("gender") != "Ů��" ) {
                say("����̾����,˵������Ҫ��Ů���Ӿͺ��ˡ�\n");
                return 1;
        }

        if( sg_exp < 200 ) {
                say("����̾����,˵������ϧ��Ĺ��Ͳ����󣬷����Ҿͽ��㡸�������С���\n");
                return 1;
        }

        if( (int)who->query_skill("meiren-sanzhao") > 30 ) {
                say("����˵�������Ѿ������ҽ����ˡ�\n");
                return 1;
        }

        message_vision("����ͬ���$N��Щ���������С��ļ��ɡ�\n", who);

        who->set_temp("su/nod", 1);
        return 1;
}

void destroy(object ob)
{
        destruct(ob);
}   

int do_learn(string arg)
{
        object ob, me = this_player();
        string skill, who;
        int gin_cost, my_skill;

        if (me->is_busy())
                return notify_fail("��������æ���ء�\n");

        if(!arg || (sscanf(arg, "%s %s", who, skill)!=2 ))
                return notify_fail("ָ���ʽ��learn|xue <ĳ��> <����>\n");

        if( me->is_fighting() )
                return notify_fail("����ĥǹ������������\n");

        if( !(ob = present(who, environment(me))) || ob != this_object() )
                return notify_fail("��Ҫ��˭��̣�\n");

        if( !living(this_object()) )
                return notify_fail("��....����Ȱ�" + name() + "Ū����˵��\n");

        if( is_busy() || is_fighting() )
                return notify_fail(name() + "������æ���ء�\n");

        if( skill != "meiren-sanzhao" )
                return notify_fail("���������±����ұ���ѧ�ˡ�\n");

        if( (my_skill = (int)me->query_skill(skill, 1)) > 30 )
                return notify_fail("���Ѿ����������ٽ����ˡ�\n");

        if( !me->query_temp("su/nod") )
                return notify_fail(name() + "����������Ը����㡣\n");

        gin_cost = 150 / (int)me->query("int");
        if( !my_skill ) {
                gin_cost *= 2;
                me->set_skill(skill,0);
        }

        if( (int)me->query("potential") <= 0 )
                return notify_fail("���Ǳ���Ѿ����ӵ������ˣ�û�а취�ٳɳ��ˡ�\n");

        printf("����%s����йء�%s�������ʡ�\n", name(), to_chinese(skill));

        tell_object(this_object(), sprintf("%s��������йء�%s�������⡣\n",
                me->name(), to_chinese(skill)));

        if( (int)me->query("jing") > gin_cost ) {
                printf("������%s��ָ������%s�ƺ���Щ�ĵá�\n",
                        name(), to_chinese(skill));
                me->improve_skill(skill, random(me->query_int()));
        } else {
                gin_cost = me->query("jing") > 0 ? (int)me->query("jing") : 0;
                write("�����̫���ˣ����ʲôҲû��ѧ����\n");
        }

        me->receive_damage("jing", gin_cost);
        return 1;
}




