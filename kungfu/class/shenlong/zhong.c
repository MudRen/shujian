//Cracked by Roath
// bailong shi ����ʹ
// ALN Sep / 97

inherit NPC;

// int auto_perform();
string ask_ob(string);
void apply_gift(object, int);

void create()
{
	set_name("��־��", ({ "zhong zhiling","bailong shi", "shi","zhong" }));
	set("nickname", "����ʹ");
	set("long",
		"����󺺣�һ����֪�ǹض��ˡ�\n");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 32);
	set("int", 26);
	set("con", 28);
	set("dex", 28);
	set("max_qi", 1200);
	set("max_jing", 1200);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jingli", 1200);
	set("max_jingli", 1200);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 50000);
	set("shen", -20000);

	set_skill("force", 100);
	set_skill("dulong-dafa", 100);
	set_skill("dodge", 80);
	set_skill("lingshe-shenfa", 80);
	set_skill("strike", 100);
	set_skill("huagu-mianzhang", 80);
	set_skill("parry", 90);
	set_skill("hook", 150);
	set_skill("ruyi-gou", 100);
//	set_skill("digging", 80);

	map_skill("force", "dulong-dafa");
	map_skill("dodge", "lingshe-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry", "huagu-mianzhang");
	map_skill("hook", "ruyi-gou");

	prepare_skill("strike", "huagu-mianzhang");

	create_family("������", 2, "ʹ��");
/*
        set("chat_chance", 20);
        set("chat_msg_combat",({
                (:auto_perform:),
        }));
*/
        set("inquiry", ([
                "������" : (:ask_ob, "jiao":),
                "�鰲ͨ" : "������������˵����",
                "�����" : "������ɸ������������룬�������Ŀ��磬�����ķ���",
                "��̥�׽���" : (:ask_ob, "wan":),
                "Ч��"   : (:ask_ob, "task":),
                "����"   : (:ask_ob, "task":),
                "����"  : (:ask_ob, "exp":),
                "����"   : "û��û�صġ�",
                "��ͷ��" : (:ask_ob, "pang":),
                "����" : (:ask_ob, "su":),
                "½����" : (:ask_ob, "lu":),
                "½���" : (:ask_ob, "lu":),
                "������" : "�����������ݵĶ������򣬴������ڳ����㵽��",
        ]));

	setup();

	carry_object("/clone/weapon/hook")->wield();
	carry_object("/clone/misc/cloth")->wear();        
}

void init()
{
        ::init();

        add_action("do_leave", "leave");
}

int do_leave(string arg)
{
        if( !arg || arg != "shenlong"
        ||  !this_player()->query_temp("zhong/nod") )
                return 0;

        if( this_object()->is_fighting() || this_object()->is_busy() )
                return notify_fail("��û������æ�ţ�\n");

        this_player()->delete("sg");
        this_player()->delete("sgjob");
        this_player()->delete("yijin_wan");
        this_player()->set("sg/cured", 1);
        apply_gift(this_player(), 0);

        command("congra " + this_player()->query("id"));
        message_vision("$N���´����ͳ�һ��ҩ��������$n�����\n", this_object(), this_player());
        command("say " + "�����պ��ڽ����Ϻ���Ϊ֮�ɡ�");
        command("bye " + this_player()->query("id"));
        call_out("destroy_zhong", 1, this_object());
        return 1;
}

void destroy_zhong(object zhong)
{
        if( !zhong ) return;

        message("vision",
                zhong->name() + "һת�۱���ʧ�ˡ�\n",
                environment(zhong), ({zhong}));

        destruct(zhong);
}

string ask_ob(string arg)
{
        if( this_player()->query("sg/cured") ) 
                return "�޳ܵ���ͽ���������ҹ�������";

        if( !this_player()->query("sg/spy") )
                return "���Ǳ̵ֽ����ܣ���ʲô���ʵģ���";

        return "���ڽ��е����飬��ȥ����ͷ�ӻ���ͷ�ӡ�";
}

void apply_gift(object me, int flag)
{
        int i;
        int tmpstr, tmpint, tmpcon, tmpdex;
        mapping my = me->query_entire_dbase();

        tmpstr = tmpint = tmpcon = tmpdex = 10 + flag;

        for (i = 0; i < 40; i++) {
                switch (random(4)) {
                        case 0: tmpstr++; break;
                        case 1: tmpint++; break;
                        case 2: tmpcon++; break;
                        case 3: tmpdex++; break;
                }
        }

        if (tmpstr <= 30) my["str"] = tmpstr;   else my["str"] = 30;
        if (tmpint <= 30) my["int"] = tmpint;   else my["int"] = 30;
        if (tmpcon <= 30) my["con"] = tmpcon;   else my["con"] = 30;
        if (tmpdex <= 30) my["dex"] = tmpdex;   else my["dex"] = 30;
}






