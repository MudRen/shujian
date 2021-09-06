//wanzhenshan.c 

inherit NPC;
#include <ansi.h>

int ask_liguan(); 
string ask_diyun();
string ask_qi();
#include "/d/suzhou/npc/lchj.h";

void create()
{
	set_name("����ɽ", ({ "wan zhenshan","wan","zhenshan", "guanzhu" }));
	set("title", "������ݹ���");
	set("nickname", "������");
	set("gender", "����");
	set("age", 62);
	set("str", 30);
	set("dex", 26);
	set("long", "�����Ͻ����ӣ�������ϣ�����������վ�����������һ��������\n");
	set("combat_exp", 100000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("unique", 1);
         
	set_skill("force", 90);
	set_skill("strike", 90);  
	set_skill("dodge", 90);
	set_skill("parry", 90);     
	set_skill("shenzhao-jing", 90);
	map_skill("force","shenzhao-jing");

	set("inquiry", ([
		"����" : "�Ǻǣ���ȥ���ҵĴ�ͽ�ܰɣ����ᰲ�����!",
		"����" : "�������䳡���������ģ���ȥ�Ƕ�����!",
		"���" : (:ask_liguan:),  
		"����" : (: ask_diyun:),	
		"�ݳ���" : (: ask_qi:),	
		"��ʫѡ��" : "��ʫѡ����......��û��˵����",
		"���Ǿ�" : "���Ǿ���......��û��˵����",
		"���ǽ���" : "ʲô���ǽ�������û��˵����",
		"�Դ�ƽ" : "������ʦ�ܡ�",
		"÷����" : "����ī��÷��������������������ʦ����",
		"�仨��ˮ":"��˵�Ŀ��������棡",
		"������":"����ƽǹ�����ɡ���",
		"���˷�":"�����ƽ����˷硱��",
		"½����":"������½�󵶡���",
		"ˮ�":"�����½�ˮᷡ���",
	]));

	setup();
	carry_object(ARMOR_D("jinduan"))->wear();
}

int ask_liguan()
{
	object ob;
	object letter;
	
	ob = this_player();
	if(! ob->query("enter_wuguan")){
		command("say �㲻���Ѿ�����������ô��");
		return 1;
	}
	if(ob ->query("combat_exp") >= 3000 && objectp(letter = new(__DIR__"obj/letter")) ) {
		command("nod "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob)+"���Գ�ȥ���������ˣ������ն񣬿�ǧ��С�İ���ȥ����"+
			"��ͽ�����ȥ˵һ���ɣ����ᰲ�ŵġ�");
		            command("say �����ն���Ҫ�������м���������ײ��ɡ�");
            
            	command("say �Ϸ������ν��ϣ�����һλ�����ཻ���ã����ǰ��Ѱ�ã����ұ������֮����");
            	command("say ����㲻��ұ������֮��������ʹ�� help dazao �����ϸ��Ϣ��");
                letter->move(ob);
                message_vision("$n��$Nһ�⡸"+letter->query("name")+"����\n",ob,  this_object());        
                   command("say �ҿ�������书��������ʵ����������ָ���㼸�У����Ҫ����ϸ�ˡ�");
ob->set_skill("force", 32);
ob->set_skill("dodge", 32);
ob->set_skill("parry", 32);
ob->set_skill("cuff", 32);
ob->set_skill("strike", 32);
ob->set_skill("leg", 32);
ob->set_skill("finger", 32);
ob->set_skill("blade", 32);
ob->set_skill("sword", 32);
ob->set_skill("staff", 32);
ob->set_skill("hand", 32);
ob->set_skill("club", 32);
ob->set_skill("whip", 32);
ob->set_skill("dagger", 32);
ob->set_skill("hook", 32);
ob->set_skill("stick", 32);
ob->set_skill("throwing", 32);
ob->set_skill("claw", 32);
                ob->delete("enter_wuguan");
		ob->delete("wgjob");
		return 1;
	}
	else {
		command("pat "+ob->query("id"));
		command("say ��λ" + RANK_D->query_respect(ob)+"�ľ��黹̫�����̫Σ�գ��㻹�ǹԹ�����������ɡ�");
		return 1;
	}
}
string ask_diyun()
{
	object me,ob;
	me = this_player();
	ob = this_object();
    if(me->query("combat_exp")<10000)
   {
    command("killair");
       return "���������ʲô��";
}
	if(!me->query(QUESTDIR1+"over") || !me->query_temp(QUESTDIR2+"start" ))
	{
	   call_out("outwuguan",1,me);
	   return "����ô��������ģ�";
	}
	if(me->query_temp(QUESTDIR2+"askwan_diyun" ))
	{
	   command("hehe");
	   return "�ٺ٣����ڵ���Ӧ�������ڼ����ɣ�";
	}
	message_vision(HIY"$N����¶���������ɫ��\n", ob);
	command("look "+me->query("id"));
	command("heng");
	command("say ����������ʦ�������ɱ�ң������Ƹ��Ǻͼ�Ů�Һ칶�ϣ�����ȥ�����Ѿ����Ŵ����ˡ�");
	command("haha");
	me->set_temp(QUESTDIR2+"askwan_diyun",1);
	if(me->query_temp(QUESTDIR2+"askwan_qi" ))
		tell_object(me,HIG"���ܸо��⻰�������⡣�����������ɽ�ƺ�����������ġ�\n"NOR);
	return "";
}
string ask_qi()
{
	object me,ob;
	me = this_player();
	ob = this_object();
	if(!me->query(QUESTDIR1+"over") || !me->query_temp(QUESTDIR2+"start" ))
	{
	   call_out("outwuguan",1,me);
	   return "����ô��������ģ�";
	}
	if(me->query_temp(QUESTDIR2+"askwan_qi" ))
	{
	   command("say");
	   return "�ٺ٣���������Ҳ��֪��......��";
	}
	command("look "+me->query("id"));
	command("haha");
	command("say �����ݳ��������ɱ�ң��ҿ��ҷ��ֵü�ʱ����Щ�꣬Ҳ��֪��������ȥ�ˡ�");
	message_vision(HIY"$N����¶���������ɫ��\n", ob);
	command("haha");
	me->set_temp(QUESTDIR2+"askwan_qi",1);
	if(me->query_temp(QUESTDIR2+"askwan_diyun" ))
		tell_object(me,HIG"���ܸо��⻰�������⡣�����������ɽ�ƺ�����������ġ�\n"NOR);
	return "";
}
void outwuguan(object me)
{
	object ob=this_object();
	object *inv;
        if(!me) return;
   if( me->query("combat_exp") <3000 ) return;
	command("?");
	message_vision(HIY"$N����¶���ɻ����ɫ��\n", ob);
	command("say ����ô��������ģ�");
	message_vision(HIR"ֻ����һ�����˰���$N��һ������������ˡ�\n"NOR, me);
	me->delete("enter_wuguan");
	inv = filter_array(deep_inventory(me), (: userp :));
	if( sizeof(inv))
		inv->move(environment(ob));
	me->unconcious();
if(me->query("combat_exp")>3000)         me->move("/d/xiangyang/damen");
	me->delete_temp("quest/busy");//
	me->delete_temp("quest/���Ǿ�");
}
