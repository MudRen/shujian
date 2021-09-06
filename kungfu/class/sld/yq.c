// ���

inherit F_MASTER;
inherit NPC;
void create()
{
        set_name("���", ({ "yin jin","yin" }));
	set("long", "����ʮ������ͣ��������̻���������ʹ��\n");
        set("gender", "����");
	set("title", "�����̻���������ʹ");	
        set("age", 42);       
	set("str", 20);
        set("int", 22);
        set("con", 22);
        set("dex", 22);
        set("per", 15);
        set("combat_exp", 500000);
        set("shen", -50000);
        set("attitude", "peaceful");
	set("max_qi",2000);
        set("max_jing",2000);
        set("neili",2000);
        set("max_neili",2000);
        set("jingli",1500);
        set("eff_jingli",1500);
	set("jiali",40);
	set("score", 20000);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry",100);
	set_skill("strike",100);
	set_skill("hook",150);
	set_skill("huagu-mianzhang", 100);
	set_skill("youlong-shenfa",100);
	set_skill("dulong-dafa",100);
	set_skill("canglang-goufa",150);
	set_skill("poison",100);
	set_skill("shenlong-yaoli",100);
   set_skill("leg", 350);
   set_skill("shenlong-tuifa", 150);
  map_skill("leg", "shenlong-tuifa");
	map_skill("force", "dulong-dafa");
	map_skill("dodge", "youlong-shenfa");
	map_skill("strike", "huagu-mianzhang");
	map_skill("hook", "canglang-goufa");
	map_skill("parry","canglang-goufa");
	prepare_skill("strike", "huagu-mianzhang");

	create_family("������",2, "����ʹ");
	setup();
	carry_object("/d/sld/npc/obj/ycp")->wear();
	carry_object(BINGQI_D("hook"))->wield();
}
     
void attempt_apprentice(object ob)
{
       mapping myfam;

       myfam = (mapping)ob->query("family");
 	if(!myfam || myfam["family_name"] != "������")
           command("say ��Ǳ��̵��ӣ�������ȥ�����ʹ��̰�.");
       else if(ob->query("shen",1) > -10000)
           command("say �㻹�����ĺ���������ȥ��ɱ�����׵����˰�");
       else if(ob->query_skill("dulong-dafa",1)<70 || ob->query_skill("huagu-mianzhang",1)<70)
                   command("shake "+ob->query("id"));
       else
            {
           command("say �ðɣ��Ҿ����������ҵĵ��ӡ�");
	    command("recruit " + ob->query("id"));
       }
	return;	
}

int recognize_apprentice(object ob)
{
    mapping myfam;
    object hw;

    myfam = (mapping)ob->query("family");
if(!myfam || (myfam["family_name"] != "������")) return 0;
     if(!ob->is_apprentice_of(this_object())) return 0;
    if(myfam && (myfam["family_name"] == "������")&&(ob->query("shen",1) >0))
    {
    	command("say �ߣ��㾹Ȼ�ҺͰ׵����˸���һ���ǲ��ǲ�����ˣ���ȥ���ݺú÷�ʡ��ʡ�ɣ�");
	if(!objectp(hw=find_object("/d/sld/npc/obj/heiwu")))
		hw=load_object("/d/sld/npc/obj/heiwu");
	ob->set("in_heiwu",time());
	ob->move(hw);        
        return 0;
    }
    return 1;
}
