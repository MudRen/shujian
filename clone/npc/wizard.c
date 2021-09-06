// wizardb.c


inherit NPC;

int ask_name();
int ask_guild();
void create()
{
	set_name("��ʦ",({"wu shi", "wizard", "wushi" }) );
        set("gender", "����" );
        set("age", 30);
        set("long", "����һ�������������µ���ʦ��\n");

        set("str", 17);
        set("dex", 16);
        set("con", 15);
        set("int", 17);
	set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 100);
        set("attitude", "peaceful");

        setup();

	set("inquiry", ([
		"name": (: ask_name :),
		"rumors": "��˵����Խ�����ϵͳ���뿪�Ž׶��ˡ�",
        	"bbb": "���������ң��ѵ�û���κα�ʾ��",
		"����": (:ask_guild :),
         	"ɱ��": "���������ң��ѵ�û���κα�ʾ��",
	]) );

        carry_object(ARMOR_D("cloth"))->wear();
}

int ask_name()
{
	object ob = this_player();

	command("smash " + ob->query("id"));
	say("û���ɣ�һ�����Ծ�smash���ˣ�׼��BBB��\n");
	return 1;
}

int ask_guild()
{
	object ob = this_player();
	int exp = ob->query("combat_exp");

//		command("say �µİ���ϵͳ���ڿ����У���ʱ����������ɡ�\n");
//		return 1;
//	if ( ob->query("g_title"))
//		say("��ʦ˵�������Ѿ��������ˡ�\n");
	if (exp >= 2000000 && (!present("lingpai",ob)))	{
          	new("/data/group/obj/ling")->move(ob);
		say("��ʦ˵������������ȥ�ɡ�����ϵͳ���н��顢BUG ���� bbb ���档\n");
	}
	if ( exp < 2000000 )
		say("��ʦ˵������ľ��鲻������ʱ���ܴ������ɡ�\n");
	if ( present("lingpai",ob))
		say("��ʦ˵�������Ѿ��������ˡ�\n");
	else	say("��ʦ˵�������������ϣ����ܴ������ɡ�\n");
	return 1;
}
