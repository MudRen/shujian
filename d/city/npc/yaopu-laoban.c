// yaopu-laoban.c ҩ���ϰ�
// by shang 97/6

inherit NPC;
inherit F_DEALER;

int ask_book();
int ask_liaoshang();
void recover(object ob);

void create()
{
	set_name("ҩ���ϰ�", ({ "yaopu laoban", "laoban", "boss" }));
	set("gender", "����");
	set("long", "һλ������ҩ���ϰ�, ��Ӫ���洫�����̡�\n");
	set("age", 65);

	set("int", 20);
	
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 300);
	set("max_jing", 300);
	set("shen_type", 1);

	set("combat_exp", 5000);
	set("attitude", "heroism");

	set_skill("unarmed", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);

	set("vendor_goods", ({
	}));
       set("inquiry", ([
       "ҽ��" : (: ask_book :),
       "ҩ��" : (: ask_book :),
		"����" : (:ask_liaoshang:),//for newbie
    ]));

	setup();
	add_money("silver", 15);
}

void init()
{
//add_action("do_buy", "buy");
}
int ask_book()
{
  command("sigh");
  command("say ����˵�Ǳ�[�ƽ𾵸�����]�ɣ�ǰ���컹���������ģ���֪�����ĸ��һ�\n"
+"˳��ǣ���͵���ˣ�������������ͷ����\n");
  this_player()->set_temp("marks/m-book4", 1);
return 1;
}
//for newbie
int ask_liaoshang()
{
	object ob;
	ob=this_player();
	if(ob->query("combat_exp")<3000) 
	{
		command("? "+ob->query("id"));     
		command("say ����ô����ݳ����˰����������Σ�հ���\n");
		command("poor "+ob->query("id"));
		return 1;
	}
	if(ob->query("combat_exp")>50000) 
	{
		command("? "+ob->query("id"));     
		command("say ���ˣ���Ǯ��ҩ������ƽ���ۣ�ͯ�����ۣ�\n");
		command("knock "+ob->query("id"));
		return 1;
	}
	if (ob->query("eff_qi") >= ob->query("max_qi"))
	{
		command("? "+ob->query("id"));     
		command("say ��Ƥ���������������ң�\n");
		command("smile "+ob->query("id"));
		return 1;
	}
	else 
	{
		message_vision("$n����$N�µ������ϰ����壬�������ˣ���ʹ��......��\n", this_object(),ob);
		command("poor "+ob->query("id"));
		command("pat "+ob->query("id"));
		command("say �ðɣ�����һ��С���ӳ�������������Ҳ�����Ľ���");
                message_vision("$N�ó�һ��������������$n���˲�λ������Ѩ����$n�о�������ˡ�\n", this_object(),ob);
		ob->start_busy(3);
		call_out("recover", 5, ob);
		return 1;
	}
}
void recover(object ob)
{
	if (!ob || !present(ob)) return;
	if (environment(ob) != environment(this_object())) return;
	ob->set("eff_qi", (int)ob->query("max_qi"));
ob->set("eff_jing", (int)ob->query("max_jing"));
	message_vision("һ����Ĺ����ȥ�ˣ�$N���������Ѿ�����Ȭ���ˡ�\n",ob);
	command("say �����ն�,��С�ĵĻ����´����û��ô�����ˡ�\n");
	command("pat "+ob->query("id"));
}
