// zdy.c �ŵ���
// Modified by Lklv add ask xionghuangjiu

inherit F_MASTER;
inherit NPC;
string ask_jiu();

void create()
{
	set_name("�ŵ���", ({ "zhang danyue","zhang" }));
	set("long", "����ʮ������ͣ��������̺���������ʹ��\n");
	set("gender", "����");
	set("title", "�����̺���������ʹ");
	set("age", 42);
	set("str", 20);
	set("int", 22);
	set("con", 22);
	set("dex", 22);
	set("per", 15);
	set("combat_exp", 200000);
	set("shen", -50000);
	set("attitude", "peaceful");
	set("max_qi",1000);
	set("max_jing",1000);
	set("neili",1000);
	set("max_neili",1000);
	set("jingli",800);
	set("eff_jingli",800);
	set("jiali",30);
	set("score", 20000);

	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("parry",50);
	set_skill("strike",50);
	set_skill("huagu-mianzhang", 50);
	set_skill("youlong-shenfa",50);
	set_skill("dulong-dafa",50);
   set_skill("leg", 150);
  set_skill("shenlong-tuifa", 150);
  map_skill("leg", "shenlong-tuifa");
	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("parry","huagu-mianzhang");
	prepare_skill("strike", "huagu-mianzhang");

	create_family("������",2, "����ʹ");
        set("inquiry", ([
                "������" : "����������������������ң���ڡ�\n",
                "�ۻƾ�" : (: ask_jiu :),
        ]));
	setup();
	carry_object("/d/sld/npc/obj/bcp")->wear();
}

void attempt_apprentice(object ob)
{
	mapping myfam;
	object ob1;

	myfam = (mapping)ob->query("family");
	if(!myfam || myfam["family_name"] != "������"){
		if(ob->query("app/sld")!=1){
			command("say �ðɣ��Ҿ����������ҵĵ��ӡ�");
			ob->set("app/sld",1);
			command("recruit " + ob->query("id"));
			tell_object(ob, "��������ۻƾƺ��ˣ��Ϳ��Բ�����ҧ�ˡ�\n");
			ob1 = new("/d/sld/npc/obj/xionghuangjiu");
			if(!ob1->move(ob))
				ob1->move(environment(ob));
			tell_room(environment(ob), "�ŵ��¸���"+ob->name()+"һ���ۻƾơ�\n");
		}
		else{
		command("say �����̲����������ѽ�֮�ˣ����߰�!");
		}
	}
}

int recognize_apprentice(object ob)
{
	mapping myfam;
	object hw;

	myfam = (mapping)ob->query("family");
	if(!myfam || (myfam["family_name"] != "������")) return 0;
	if(!ob->is_apprentice_of(this_object())) return 0;
	if(myfam && (myfam["family_name"] == "������")&&(ob->query("shen",1) >0)){
		command("say �ߣ��㾹Ȼ�ҺͰ׵����˸���һ���ǲ��ǲ�����ˣ���ȥ���ݺú÷�ʡ��ʡ�ɣ�");
		if(!objectp(hw=find_object("/d/sld/npc/obj/heiwu")))
			hw=load_object("/d/sld/npc/obj/heiwu");
		ob->set("in_heiwu",time());
		ob->move(hw);
		return 0;
	}
	return 1;
}

string ask_jiu()
{
        object ob, me = this_player();

	if (me->query("family/family_name") != "������")
                return "ȥ�ұ��˰ɣ��ҿɲ������㣡";
        if (me->query("xionghuangjiu"))
                return "������Ѿ��ȹ��ۻƾ��ˣ��ٺȲ��º����㣿";

        if (present("xionghuang jiu", me))
                return "�����ϻ����ۻƾưɡ�";

        ob = new("/d/sld/npc/obj/xionghuangjiu");
        ob->move(me);
        message_vision("�ŵ��µݸ�$Nһ���ۻƾơ�\n", me);
        return "��������ۻƾƺ��ˣ��Ͳ�����ҧ�ˡ�";
}
