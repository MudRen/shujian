// NPC: /d/huashan/npc/linghuchong.c
// Date: Look 99/03/25
// Modified by Numa@JH 2000 For ��ľ��Job
// Lklv Modify at 2001.10.18
// update by lsxk@hsbbs ���ӻ�ɽ��������ӭ�� quest  2007/7/29

#include <ansi.h>
inherit NPC;
#include "skill1.h"

string ask_chongling();
string ask_ylj1();
string ask_ylj2();
string ask_ylj3();
int ask_ryy();
int ask_heimu();
int ask_follow();
int ask_cangsong();

void create()
{
        set_name("�����", ({ "linghu chong", "linghu", "chong" }));
        set("nickname", "��ʦ��");
        set("long",
"�����Ľ��ݣ�����Ũü���ۣ������Ѱ�������\n"
"ͬ���������ϴ��ǻ�ɽ������һ���еĶ�����֡�\n"
"�������������Ⱥ���ڣ�������ִ���ճ����\n");
        set("gender", "����");
        set("age", 28);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("dex", 30);
        set("unique", 1);

        set("max_qi", 3000);
        set("max_jing", 1800);
        set("neili", 4000);
        set("max_neili", 4000);
        set("eff_jingli", 1800);

        set("jiali", 60);
        set("combat_exp", 800000);
        set("score", 8000);
        set("startroom","/d/huashan/siguoya");

        set_skill("cuff", 120);
        set_skill("force", 120);
        set_skill("dodge", 120);
        set_skill("parry", 120);
        set_skill("sword", 120);
        set_skill("dugu-jiujian", 120);
        set_skill("zixia-gong", 120);
        set_skill("poyu-quan", 120);
        set_skill("huashan-jianfa", 120);
        set_skill("huashan-shenfa",120);
        set_skill("zhengqi-jue", 120);
        set_skill("chongling-jian", 120);

        map_skill("force", "zixia-gong");
        map_skill("cuff", "poyu-quan");
        map_skill("dodge", "huashan-shenfa");
        map_skill("parry", "huashan-jianfa");
        map_skill("sword", "huashan-jianfa");

        prepare_skill("cuff", "poyu-quan");

        create_family("��ɽ��", 14, "����");
        set("chat_msg_combat", ({
                (: random_move :)
        }) );
        set("chat_chance", 15);

        set("inquiry", ([
                "������" : "�����Ѿ��ܾ�û�м��������˼��ˡ���������\n",
                "����ɺ" : "����Сʦ����ʲô�°���\n",
                "����" : "������ã���ı���\n",
                "��ϼ�ؼ�" : "�������ǻ�ɽ���ڹ��ؼ�����û�п�����\n",
                "����" : (: ask_ylj3 :),
                "ī������" : (: ask_ylj2 :),
                "���齣��" : (: ask_chongling :),
                "������ã���ı���" : (: ask_ylj1 :),
                 "����ӭ��" : (: ask_cangsong :),
// add here for ask
                "��ӯӯ" : (: ask_ryy :),
                "��ľ��" : (: ask_heimu :),
                "follow" : (: ask_follow :),
        ]));
        setup();
        carry_object(BINGQI_D("sword/sword"))->wield();
        carry_object(ARMOR_D("armor/cloth"))->wear();
}

int ask_cangsong()
{
    mapping fam;
    object me = this_player();
    fam = me->query("family");

    if (!fam || fam["family_name"] !="��ɽ��"){
        command("say ��λ" + RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��");
        return  1;
    }
/*
    if (me->query("quest/huashan")!="����"){
        command("say �һ�ɽ��������ѧ������Ԧ�������¿���λ" + RANK_D->query_respect(me)+"����֮���˽�����������������⡸����ӭ�͡����о���֮����");
        return 1;
}

*/
    if ((int)me->query_skill("huashan-jianfa",1)<180){
        command("say �һ�ɽ�ɽ�������ѭ�򽥽���ϰ���г�Ч����λ" + RANK_D->query_respect(me)+"��Ļ�ɽ�����в������죬��������⡸����ӭ�͡����о���֮����");
        return 1;
    }
    if ((int)me->query("combat_exp")<400000){
        command("say �һ�ɽ�ɽ���ע��ƽʱ��ϰ�����۾��飬��λ" + RANK_D->query_respect(me)+"ʵս����ʵ��̫ǳ����������⡸����ӭ�͡����о���֮����");
        return 1;
    }
    if (me->query_condition("job_busy")){
        command("say ��λ" + RANK_D->query_respect(me)+"������ôæ���ѵ�����ʱ��ȥ��ᡸ����ӭ�͡���ô����Ľ�����");
        return 1;
    }
    if (me->query("quest/hsjf/cangsong")=="pass"){
        command("say ��λ"+ RANK_D->query_respect(me)+"�����Ѿ�ѧ����ô���ѵ������ˣ�");
        command("admire " + me->query("id"));
        return 1;
    }
    if ((int)me->query("quest/hsjf/cs_time")+86400 > time()){
        command("shake "+ me->query("id"));
        command("say �㻹���ٶ�໨Щʱ����˼�����ŵ��书�ɣ�");
        return 1;
    }
    if (me->query_temp("quest/hsjf/cangsong/asked")){
        command("? " + me->query("id"));
        return 1;
    }
    command("haha");
    command("say �����������ɸ��ɽ�����������ɫ���һ�ɽ�ɽ���֮����һ���һ�ɽ��ϼ�񹦣����˽�����ӯ�鶯���仯�޷���");
    command("say "+strip(me->query("name"))+"�������һ�ɽ��ϰ��Ҳ�в��������ˣ���֪���һ�ɽ�����ľ�Ҫ��ʲô��");
    me->set_temp("quest/hsjf/cangsong/asked",1);
    add_action("do_answer","answer");
    return 1;
}


int do_answer(string arg)
{
    object me, ob, cs_npc;
    int i;

    me = this_player();
    ob = this_object();

    if(!objectp(me)) return 1;

    if(!me->query_temp("quest/hsjf/cangsong/asked")) return 0;

    if(!arg) return notify_fail("����ش�ʲô?\n");

    if(arg!="����Ԧ��" && (int)me->query_temp("quest/hsjf/cs_answer_err") < 2){
        me->add_temp("quest/hsjf/cs_answer_err",1);
        command("shake " + me->query("id"));
        command("say ������ϸ���롣");
        return 1;
    }
    else if(arg!="����Ԧ��" && (int)me->query_temp("quest/hsjf/cs_answer_err") >= 2){
        command("sigh " + me->query("id"));
        command("say ������Ա����书����֪��ǳ��������Ŭ�����ǡ���λ"+ RANK_D->query_respect(me)+"������ذɣ�");
        me->set("quest/hsjf/cs_time",time());
        me->set("quest/hsjf/cangsong","fail");
        me->delete_temp("quest/hsjf/cs_answer_err");
        me->delete_temp("quest/hsjf/cangsong/asked");
        return 1;
    }
    command("pat " + me->query("id"));
    command("say ������������ˣ����С�����ӭ�͡��������������У��ټ��Ͻ���������ϼ���ھ�����������������ڵ����κ�һ���书���У�");
    command("say ��˵�����޷���ᣬ����������˵��һ���������ȥ���ݳ��������ȥ�����Ƕ�������!");
    command("say һ��ȥ�Ͷ����ƣ�����������⡸����ӭ�͡����еľ���֮�����мǣ�Ҫ�����ϰʹ�ò����л����ڻ��ͨ��");
    for(i=0;i<4;i++){
        cs_npc = new(__DIR__"cs_npc");
        cs_npc->set("cs_kill_id",me->query("id"));
        cs_npc->move("/d/fuzhou/zhongxin");
    }
    me->set("quest/hsjf/cs_time",time());
    me->set("quest/hsjf/cangsong","start_kill");
    me->delete_temp("quest/hsjf/cs_answer_err");
    me->delete_temp("quest/hsjf/cangsong/asked");
    return 1;
}

string ask_chongling()
{
        mapping fam;
        object me;
        me = this_player();
        fam = me->query("family");
	if (!fam || fam["family_name"] !="��ɽ��")
		return RANK_D->query_respect(me)+"�뱾��������������֪�˻��Ӻ�̸��\n";
	if (!me->query("hs/getchongling"))
		return "���齣���������Һ�Сʦ���ڳ������轣ʱ��������";
	if ((int)me->query_skill("chongling-jian", 1) > 60 )
		return "���齣�����ڶ������㻹���Լ�����ȥ�ɡ�\n";
	if ((int)me->query("jingli", 1) < 100 )
		return "����������״��̫���ˣ����޷�������齣���ľ���֮����\n";
	if ((int)me->query("jing", 1) < 100 )
		return "����������״��̫���ˣ����޷�������齣���ľ���֮����\n";
	me->improve_skill("chongling-jian", 20);
	me->receive_damage("jingli",30);
	me->receive_damage("jing", 30);
	me->start_busy(3);
	tell_object(me, HIC"�㲻���������������Ȼ��ţ��Խ���������������һ�㡣\n"NOR);
	return  "�ðɣ���Ȼ�������ҳ��齣�����Ҿ͸�����һ�Ρ�\n" ;
}

string ask_ylj1()
{
        object me;
        me = this_player();
        command("haha "+me->query("id"));
        me->set_temp("ylj/step1",1);
        return "��̨Ҳ֪������£����ǵ����ֵ���Ϊ�Ⱥ�ɽ�ɵ�����ʦ\n
�ã���ɻ�����ﲮ�⿪����Ц���º��ɽ�Ķ���ʦ������û���ң���������\n
һ�������Ѿ�����ī��������Ҫ����������һ�Ѿ�����������������Ц����\n
��.....\n";
}

string ask_ylj2()
{
        object me;
        me = this_player();
        if( !me->query_temp("ylj/step1") )
                return "����Ǹ��������ܡ�\n";
        me->set_temp("ylj/step2",1);
        me->delete_temp("ylj/step1");
        return "˵����ī������Ҳ��һ�������һֱ�Ҳ���������ʦ��\n
�����˷����������...��\n";
}

string ask_ylj3()
{
        object me, obj;
        me = this_player();
        if (!me->query_temp("ylj/step2") )
                return "����Ǹ��������ܡ�\n";
        me->delete_temp("ylj/step2");
        command("look "+me->query("id"));
        if ((int)me->query("shen") > 100000 ){
                obj = unew(__DIR__"obj/xuantie");
                if( clonep(obj) ) {
                        obj->move(me);
                        me->set_temp("ylj/step3",1);
                        return "����̨һ�����������������������̨������̨���ҵ���\n
����ʦ�����ɱ���������������Ҳ�����Ѷ���ʦ����һ������.....\n";
                }
        }
        return "����Ǹ��������ܡ�\n";
}

int ask_ryy()
{
        object ob = this_player();

        if (ob->query_temp("hostage/job_1") != 2) {
                command("say �Һܾ�û�������ˣ�");
                command("sigh");
                return 1;
        }
        ob->set_temp("hostage/ask_ling",1);
        command("ah " + ob->query("id"));
        command("say �������������������ô���ˣ�");
        command("say ���ĺ�ľ�������������뻹�����ء�");
        return 1;
}


int ask_heimu()
{
        object ob = this_player();
        object me = this_object();

        if (!ob->query_temp("hostage/ask_ling")){
                command("say "+RANK_D->query_respect(ob)+"�������²�����ô����ģ�");
                return 1;
        }

        command("say ��Ҫ��ľ��ٺ٣����������Ա��ԣ�Ӯ���Ҿ͸��㣡");
        ob->set_temp("hostage/pass_l",1);
        call_out("do_clone",1,me,ob);
        return 1;
}

int accept_fight(object ob)
{
        object me = this_object();

        if ((int)ob->query_temp("hostage/passed_l")){
                command("say ���ǲ��Ǳ��Թ�����");
                return 0;
        }
        if (me->query("eff_qi") < me->query("max_qi")
        || me->query("qi") < me->query("eff_qi")
        || me->query("neili") < me->query("max_neili")){
        	me->reincarnate();
                message_vision(CYN"$N��$n˵���һ�û����Ϣ�ã����һ����ɡ�\n"NOR, ob, me);
                return 0;
        }
        if (ob->query_temp("hostage/pass_l")){
                message_vision(CYN"$N��$n˵���ðɣ����Ҿ�ͬ���д꼸�аɣ��㵽Ϊֹ��\n"NOR, ob, me);
                remove_call_out("checking");
                call_out("checking", 1, me, ob);
                ob->delete_temp("hostage/pass_l");
                return 1;
        }
        else return 0;
}

int checking(object me, object ob)
{
        int my_max_qi,his_max_qi;
        my_max_qi  = (int)me->query("max_qi");
        his_max_qi = (int)ob->query("max_qi");

        if ( !present(ob, environment()) )
                return 1;
        if (( (int)me->query("qi")*100 / my_max_qi) <= 50 ){
                message_vision(CYN"$N��$n��ס����̾��"+RANK_D->query_respect(ob)+"��Ȼ�ù�������ȴ���ȥ��ӯӯ����ɡ�\n"NOR, me, ob);
                ob->set_temp("hostage/passed_l", 1);
                if (me->query("block_msg/all")>0) {
                        me->revive();
                }
                me->reincarnate();
                me->set_leader(ob);
                me->delete("chat_chance");
                me->set("location",1);
                me->set_temp("no_return",1);
                message_vision("$N��������$nһ���ж���\n"NOR, me, ob);
                return 1;
        }
        if (( (int)ob->query("qi")*100 / his_max_qi) < 50 ){
                message_vision(CYN"$N���˿�$n��˵������Ĺ���ϡ��ƽ������ô����ȥ����ӯӯ��\n"NOR, me,ob);
                message_vision("$N����ææ�뿪�ˡ�\n",me);
                ob->set_temp("hostage/passno_l", 1);
                me->move(__DIR__"siguoya");
                message_vision("$N����ææ���˹�����\n", me);
                return 1;
        }
        if (me->is_fighting()) {
                call_out("checking",1, me, ob);
                return 1;
        }
        return 1;
}

int ask_follow()
{
        object ob = this_object();
        object me = this_player();

        if (!me->query_temp("hostage/passed_l"))
                return 0;
        message_vision(CYN"$n������Ц������$N˵�����Ǿ��߰ɣ�\n"NOR,me,ob);
        ob->set_leader(me);
        message_vision("$n��������$Nһ���ж���\n"NOR,me,ob);
        ob->delete("chat_chance");
        return 1;
}
