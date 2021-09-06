//xuemuh.c ѦĽ��
// shilling 97.2

inherit NPC;
//inherit F_MASTER;

//void attempt_apprentice(object ob);
int ask_me();

void create()
{
	set_name("ѦĽ��", ({ "xue muhua", "xue" }));
	set("long", 
		"�����Ǻų������е���ҽ����ѦĽ������˵����ͨҽ����������������\n");
	set("gender", "����");
	set("title","��ң�ɡ����Ȱ��ѡ�");
	set("nickname","������Ѧ��ҽ");
	set("age", 50);
	set("class", "shaman");
	set("attitude", "peaceful");
	set("str", 25);
	set("int", 27);
	set("con", 25);
	set("dex", 25);
	set("inquiry", ([
		"����" : (:ask_me:),
	]) );

	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 60);
	set("combat_exp", 150000);
	set("score", 80000);

	set_skill("force", 220);
	set_skill("dodge", 220);
	set_skill("medicine",220);
	set_skill("parry", 220);
	set_skill("hand", 220);
	set_skill("qingyun-shou", 150);
	set_skill("piaomiao-shenfa",180);
	set_skill("beiming-shengong", 180);
	set_skill("zhemei-shou", 180);
	set_skill("literate", 200);
	set_skill("art", 160);

	map_skill("hand", "zhemei-shou");
	map_skill("dodge", "piaomiao-shenfa");
	map_skill("force", "beiming-shengong");

	prepare_skill("hand","zhemei-shou");

	create_family("��ң��", 3, "����");
	setup();
	carry_object(__DIR__"obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
 if ((string)ob->query("gender")=="����")
{
            message_vision("ѦĽ����Ŀ��˼Ƭ��, ˵�������ð�, �Ҿ��������ˡ���\n",ob);
       command("recruit " + ob->query("id"));
        return;}

    else
{
                 message_vision("����ң�ɴӲ���Ů��֮����\n",ob);
        return;}
 }

int ask_me()
{
	object ob;
	ob=this_player();

	if (ob->query("family/family_name") != "��ң��")
		return notify_fail("�㲻�����ɵ��ӣ��Ҳ�����Ϊ�����ˡ�\n");
	if ((int)ob->query("eff_qi") == (int)ob->query("max_qi"))
	{
		command("?"+ob->query("id"));     
		command("say ��û�����κ��˰���\n");
		return 1;
	}
	else
	{
		message_vision("ѦĽ��ι$N����һ��ҩ��,Ȼ����ϥ���£�˫������$N�ı��ġ�\n", ob);
		remove_call_out("recover");
		call_out("recover",2,ob);
		return 1;
	}
}


int recover(object ob)
{
	ob->set("eff_qi", (int)ob->query("max_qi"));
	ob->set("eff_jing", (int)ob->query("max_jing"));  
	message_vision("��Լ����һ�Ѳ��ʱ�ݣ�ѦĽ��������վ��������\n",ob);
	command("say ��������Ѿ�ȫ����,����������\n");
	return 1;
}
