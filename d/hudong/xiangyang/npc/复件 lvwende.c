// /d/xiangyang/npc/lvwende.c
// by looklove 2000/8/23
// add ����ϴ������ cigarman 16/02/2008
#include <ansi.h>
inherit NPC;
#define HDJOB "/adm/daemons/hdjob.c"
#define HD_TEST 1
#define MAX_HDNUM 40
int ask_me1();
string ask_me();
void destroy(object ob)
{
        destruct(ob);
        return;
}
void create()
{
        set_name("���ĵ�", ({ "lv wende", "lv" }));
        set("title", "����֪��");
        set("gender", "����");
        set("age", 40);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("long", "��������������֪����������������ξ������ɹ����ӶԿ���\n");
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        set("max_qi", 1200);
        set("max_jing", 1200);
        set("eff_jingli", 1000);
        set("jiali", 30);
        set_skill("force", 70);
        set_skill("unarmed", 80);
        set_skill("strike", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        set_skill("qingmang-jian", 80);        map_skill("sword", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        map_skill("parry", "qingmang-jian");
        set("inquiry", ([
                "����Ͷ��" : (: ask_me :),
                "Э������" : (: ask_me1 :),
        ]));
        setup();
        carry_object(ARMOR_D("guanxue"))->wear();
        carry_object(ARMOR_D("changshan4"))->wear();
}

void kill_ob(object ob)
{
        command("say �󵨣�����ɱ��͢���٣�");
        return ;
}
int ask_me1()
{
          int i, a_exp = 0, d_exp= 0;
object ob =this_object();
object *obj;
      object me = this_player();

          if(!ob->query("hd_start")){
                command("say ��̽��������Ŀǰ�ɹŴ����û�����Ҵ��α߹أ�");
                return 1; } 
          if(me->query_condition("killer")){
                command("say ��͢����ͨ�����أ���Ȼ�һ������У���Ҳ���ҵ��ﳯ͢��");
                return 1; } 
                if(base_name(environment(ob))!="/d/hudong/xiangyang/defend") {
                command("say �ҳ������⣬�������");
                return 1; }             if(me->query("combat_exp") < 100000){
                message_vision("$N��$n˵������λ"+RANK_D->query_respect(me)+"��ս���ն��㻹�ǻ�ȥ�úö����ɣ�\n",ob,me);
                return 1; } 
                if(me->query_temp("��������/������ս/ask_ok")==1){
                command("say ���Ѿ���Э���Ҿ����������ˣ���ȥ����׼���ɣ�");
                return 1; } 
                if(me->query_temp("��������/������ս/ask_ok")==2){
                command("say ���������ģ����Ī�����ɹ����ӵļ�ϸ��");
                return 1; } 
                              



                 message_vision(CYN"\n$N������Ц����"+RANK_D->query_respect(me)+"�ϴ���Ԯ�֣��ɹ����������ȡ����������Ҫ����ˡ�\n"NOR, ob, me);
                 message_vision(CYN"\n$N��$n˵������Ȼ��ˣ�"+RANK_D->query_respect(me)+"�͸Ͽ���ȥ׼��׼���ɣ��ɹ�������ʱ���ṥ���ˡ�\n"NOR, ob, me);                 me->set_temp("��������/������ս/ask_ok",1);
                 me->set_temp("��������/hdflag","������ս");
me->set_temp("��������/������ս/defend",1);

                 me->set_temp("title",HIY"������ʿ"NOR);
                                return 1;
}
int check_player(object me,string arg)
{
	if(userp(me) && me->query_temp(arg))
		return 1;
		else
		return 0;
}
