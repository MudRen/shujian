// NPC: /d/huashan/npc/feng.c
// Date: Look 99/03/25
// Modify by Lklv 2001.10.18
// By KinGSo ���Ӷ��¾Ž� ������ʽ 2010

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_wuzhao();

void create()
{
	set_name("������", ( {"feng qingyang","feng","qingyang"} ) );
	set("long", "����������ɫ�����������ֽ��\n" );
	create_family("��ɽ��", 12, "����");

	set("age", 91);
	set("gender", "����");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("shen",150000);
	set("no_quest",1);

        set("con", 30);
        set("dex", 30);
        set("int", 40);
        set("str", 30);
	set("per", 24);
        set("max_jing", 6000);
        set("max_neili", 15000);
        set("max_qi", 7500);
        set("eff_jingli", 4000);
        set("neili", 15000);
        set("jiali", 100);
        set("combat_exp", 3000000);

        set_skill("sword",550);
        set_skill("force",200);
        set_skill("dodge",300);
	set_skill("poyu-quan", 280);
	set_skill("cuff", 280);
        set_skill("parry",300);
        set_skill("dugu-jiujian",550);
        set_skill("huashan-shenfa",300);
        set_skill("huashan-jianfa",200);
        set_skill("huashan-qigong",200);
        set_skill("zhengqi-jue",200);
        set_skill("hunyuan-zhang",300);
        set_skill("strike",300);

        map_skill("force","huashan-qigong");
        map_skill("sword","dugu-jiujian");
        map_skill("dodge","huashan-shenfa");
	map_skill("parry","dugu-jiujian");
	map_skill("cuff", "poyu-quan");
	map_skill("strike", "hunyuan-zhang");
	prepare_skill("strike", "hunyuan-zhang");

	set_temp("apply/damage", 40);
        set_temp("apply/dodge", 40);
        set_temp("apply/attack", 40);
        set_temp("apply/armor", 40);
       set("inquiry", ([
       "������ʽ"      : (: ask_wuzhao :),
			]));


	setup();

        carry_object(BINGQI_D("sword"))->wield();
        carry_object(ARMOR_D("cloth"))->wear();
}

void attempt_apprentice(object ob)
{
        if (!ob->query("fengset")) {
		command("say ���ҿ��½�����Ե����λ" + RANK_D->query_respect(ob)+"������ذɡ�");
		command("wave " + ob->query("id"));
		return;
        }
        if (ob->query("shen") < 100000 ) {
		command("say �һ�ɽ�����������������ɣ��Ե���Ҫ���ϡ�");
		command("say �ڵ��з��棬" + RANK_D->query_respect(ob) + "�Ƿ����ò�����");
		return;
        }
        if ((int)ob->query_skill("huashan-qigong",1) < 180)
        if ((int)ob->query_skill("zixia-gong",1) < 180){
                command("say ��λ" + RANK_D->query_respect(ob)+
                        "����������ڹ��ȼ����ͣ��²��������Ҷ��¾Ž����衣");
                return;
        }
        if ((int)ob->query_skill("huashan-shenfa",1) < 180){
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "����Ļ�ɽ���ȼ����ͣ��²��������Ҷ��¾Ž����衣");
                return;
        }
        if ((int)ob->query_skill("huashan-jianfa",1) < 180){
                command("say ��λ" + RANK_D->query_respect(ob) +
                        "����Ļ�ɽ�����ȼ����ͣ��²��������Ҷ��¾Ž����衣");
                return;
        }
        command("say �ðɣ��Ҿ���������,���ҪΪ���ǻ�ɽ����������");
        command("chat* ���ϸ��ֳ�һ˿Ц�ݣ�����"+ob->query("name")+"Ц�����һ�ɽ��������ˡ�");
        command("chat* nomatch feng");
        command("recruit " + ob->query("id"));
        ob->set("title", HIW"��ɽ�ɷ����ﴫ��"NOR);
        ob->set("quest/huashan","����");
if( ob->query_skill("zixia-gong",1) > ob->query("huashan-qigong",1)  ) ob->set_skill("huashan-qigong",ob->query_skill("zixia-gong",1)); 
if( !ob->query("quest/zixia/pass") ) ob->delete_skill("zixia-gong");
}

string ask_wuzhao()
{
    object me;
    mapping fam;
    int time;
    me=this_player();
   if ( mapp(fam=me->query("family"))
    && (string)fam["family_name"] != "��ɽ��"){
    command("? "+me->query("id"));
    return "��λ" + RANK_D->query_respect(me) + "��������˵�Ķ��¾Ž�����\n";
    }
   
   if (me->query("quest/huashan")=="����")
       return "����Ԧ������ֱ���Ǻ�����\n";

   if ((int)me->query("combat_exp") < 2700000)
       return "���ʵս���黹���㣬�޷������¾Ž��ġ�������ʽ����\n";

   if(me->query("quest/pass/dugu-jiujian/wuzhao", 1))
{
me->set("title",HIW"�¶������"NOR);
me->set_temp("title",HIW"�¶������"NOR);
      return"�㲻���Ѿ�������������ʽ������ǲ��ͷ���ң�\n";
}
        

   if(me->query("int") < 35)
		return"���¾Ž�������Ҫ���ߵ����ԣ����ҿ�" + RANK_D->query_respect(me) + "�������ƺ��޷���⣿\n";
		
   
   if(me->query("dex") < 32)
		return"���¾Ž�������Ҫ���ߵ��鶯�ԣ����ҿ�" + RANK_D->query_respect(me) + "�������ƺ��޷�ʩչ��\n";
		
   if ((int)me->query_skill("dugu-jiujian",1) < 450)
                return"��λ" + RANK_D->query_respect(me)+"����Ķ��¾Ž��ȼ����ͣ��²��������Ҷ��¾Ž����塣\n";


time=time() - me->query("quest/wuzhao/time");

if( time<=86400 )
	
	   return"���¾Ž���Ҫּ����һ�������֣��Ҳ����Ѿ����߹�������\n";
        
        command("say ���¾Ž���Ҫּ����һ�������֣�����������Ӳ�ǡ�");
        command("say ������ͨ������Ž��Ľ��⣬������ʩ�����ɣ����ǽ�ȫ���仯�������ǣ�Ҳ����ɡ�");
        command("say �ٵ�֮�ʣ��������ǵ�Խ�ɾ����ף�Խ����ԭ�������ľ�����");
        command("say �������У����˱��޷����ƣ�����ʤ���У��˽���֮���衣��");
        command("addoil" + me->query("id"));
me->set("quest/wuzhao/time",time());
me->set_temp("quest/wuzhao/ask",1);        
		return HIG"��ѧ��ʹ��ֻ�ǵ�һ����Ҫ�����������У��ǲ�����̤���˸��ֵľ��硣\n"NOR;

}









