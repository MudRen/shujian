// mohebasi.c Ħڭ��˼
// by iceland

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_write();

void create()
{
        set_name("Ħڭ��˼", ({ "mohe basi", "mohebasi" ,"mohe","basi" }));
        set("long",@LONG
����������ݸߣ���ɫ����͸�졣��ԭ����������ֻ��𷨣������Ժ�
ȴ���������书������Ϊ����̫�����Գɾͷǳ����ޡ�
LONG
        );
        set("title", HIY "�����µ�ʮ��������" NOR);
        set("gender", "����");
        set("age", 49);
        set("attitude", "friendly");
        set("shen_type", -1);
        set("str", 20);
        set("int", 15);
        set("con", 22);
        set("dex", 24);
        set("max_qi", 700);
        set("eff_jing", 400);
	set("max_jing",400);
        set("neili", 700);
        set("max_neili", 700);
        set("jiali", 30);
        set("combat_exp", 100000);
        set("score", 20000);
	set("unique", 1);

        set_skill("huanxi-chan", 50);
        set_skill("literate", 50);
        set_skill("force", 50);
        set_skill("longxiang-boruo", 50);
        set_skill("dodge", 50);
        set_skill("yuxue-dunxing", 50);
        set_skill("hand", 50);
        set_skill("dashou-yin", 50);
        set_skill("claw", 50);
        set_skill("tianwang-zhua", 50);
        set_skill("parry", 50 );

        map_skill("force", "longxiang-boruo");
        map_skill("dodge", "yuxue-dunxing");
        map_skill("hand", "dashou-yin");
        map_skill("parry", "tianwang-zhua");
        map_skill("claw", "tianwang-zhua");

        prepare_skill("hand","dashou-yin");
        prepare_skill("claw","tianwang-zhua");

        set("write_count", 3);
        set("inquiry", ([
                "д��" : (: ask_write :),
                "д����" : (: ask_write :),
        ]));

        create_family("������", 13, "����");
        set("class", "huanxi");

        setup();
        carry_object("/d/xueshan/npc/obj/qinxiu-jiasha")->wear();

        add_money("silver",50);
}

void attempt_apprentice(object ob)
{
	mapping myfam;
	myfam = (mapping)ob->query("family");

	if (myfam && myfam["family_name"] == "������"){
		command("ah "+(string)ob->query("id"));
		command("say "+ RANK_D->query_respect(ob) +"����ǫ�飬���ǹ�ͬ��ϰ����Σ�\n");
		return;
	}

	if( (string)ob->query("gender") == "����" ){
		command ("say ʩ�������ȱ�����¿ɲ�������");
		return;
	}
/*
	if( (int)ob->query("combat_exp") > 10000 ){
		command ("say ����Ĺ���ɾ����Ѿ�ûʲô�ɽ̵��ˣ�����Ϊʦ����θҵ���");
                return;
	}
*/
	if( (int)ob->query("str") < 20 ){
		command ("say �������޸���֮�����ܸ�ʲô����׳԰׺����帣ô��");
                return;
	}
	if( (int)ob->query("con") < 20 ){
		command ("say �����������ѩ���ϣ��������嵥���������ǳԲ���ѽ��");
                return;
	}
	command("say �ðɣ��Ժ�������������е������ۣ���Щ�ӻ�ɡ�");
	command("recruit " + ob->query("id"));
	ob->set("join_age",(int)ob->query("age"));
}

 string ask_write()
{
	object ob,obj,obj1;
	ob = this_player();
	
       if ((string)ob->query("family/family_name") != "������") 
                return RANK_D->query_respect(ob) +
                        "����Ľ���ɷ��棬�Ƿ�Ӧ�����������ƣ����������أ�";
	if (present("mao bi", ob) && present("bo juan",ob))
		return RANK_D->query_respect(this_player()) + 
		"����������д������������ȫ����������Ҫ�ˣ�";

	if (query("write_count") < 1)
		return "Ħڭ��˼���Ǹ���˵������ϧ�����Ĳ��ɣ����������û�бʺͲ����ˡ���";

                obj=new(MISC_D("bojuan"));
        obj1=new(BINGQI_D("maobi"));
                obj->move(ob);
                obj1->move(ob);
                add("write_count", -1);

	message_vision("Ħڭ��˼���ʺͲ������$N��\n",ob);

        return "Ħڭ��˼���΢Ц���������գ����գ�"+RANK_D->query_respect(ob)+"�ڷܺ�ѧ�����������������";
}
