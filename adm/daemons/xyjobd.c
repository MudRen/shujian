#include <ansi.h>
#include <command.h>
inherit F_DBASE;
#include <command.h>
#define QINGLONG "/d/hudong/xiangyang/qinglongmen"
#define BAIHU "/d/hudong/xiangyang/baihumen"
#define ZHUQUE "/d/hudong/xiangyang/zhuquemen"
#define XUANWU "/d/hudong/xiangyang/baihumen"
void create()
{
        seteuid(ROOT_UID);
     set("channel_id", "������ս����");
        
        set("name","");
	remove_call_out("xyjob_1");
call_out("xyjob_1", 5); 
}
string* xyjob_room = ({
        "d/hudong/xiangyang/baihumen",
        "d/hudong/xiangyang/bank",
        "d/hudong/xiangyang/baozipu",
        "d/hudong/xiangyang/bcx1",
        "d/hudong/xiangyang/bcx2",
        "d/hudong/xiangyang/bcx3",
        "d/hudong/xiangyang/bcx4",
        "d/hudong/xiangyang/bhmnj",
        "d/hudong/xiangyang/bingying",
        "d/hudong/xiangyang/bjie1",
        "d/hudong/xiangyang/bjie2",
        "d/hudong/xiangyang/bjie3",
        "d/hudong/xiangyang/chalou",
        "d/hudong/xiangyang/chalou2",
        "d/hudong/xiangyang/chayedian",
        "d/hudong/xiangyang/chemahang",
        "d/hudong/xiangyang/eroad1",
        "d/hudong/xiangyang/chengyipu",
        "d/hudong/xiangyang/chucshi",
        "d/hudong/xiangyang/cross1",
        "d/hudong/xiangyang/cross2",
        "d/hudong/xiangyang/chengyipu",
        "d/hudong/xiangyang/damen",
        "d/hudong/xiangyang/datiepu",
        "d/hudong/xiangyang/dcx1",
        "d/hudong/xiangyang/dcx2",
        "d/hudong/xiangyang/dcx3",
        "d/hudong/xiangyang/dcx4",
        "d/hudong/xiangyang/dcx5",
        "d/hudong/xiangyang/djie1",
        "d/hudong/xiangyang/djie2",
        "d/hudong/xiangyang/doufufang",


        "d/hudong/xiangyang/dpailou",
        "d/hudong/xiangyang/eroad1",
        "d/hudong/xiangyang/feizhai",
        "d/hudong/xiangyang/guangc",
        "d/hudong/xiangyang/junying",
        "d/hudong/xiangyang/mujiangpu",
        "d/hudong/xiangyang/ncx1",
        "d/hudong/xiangyang/ncx2",
        "d/hudong/xiangyang/ncx4",
        "d/hudong/xiangyang/ncx3",
        "d/hudong/xiangyang/ncx5",
        "d/hudong/xiangyang/njie1",
        "d/hudong/xiangyang/njie2",
        "d/hudong/xiangyang/njie3",
        "d/hudong/xiangyang/nroad1",
        "d/hudong/xiangyang/outeroad1",
        "d/hudong/xiangyang/outnroad1",
        "d/hudong/xiangyang/outsroad1",
        "d/hudong/xiangyang/outwroad1",
        "d/hudong/xiangyang/qinglongmen",
        "d/hudong/xiangyang/shaobingpu",
        "d/hudong/xiangyang/shuoshug",
        "d/hudong/xiangyang/sishu",
        "d/hudong/xiangyang/xcx1",
        "d/hudong/xiangyang/xiaocd",
        "d/hudong/xiangyang/xcx2",
        "d/hudong/xiangyang/xcx3",
        "d/hudong/xiangyang/xcx4",
        "d/hudong/xiangyang/xcx5",
        "d/hudong/xiangyang/xiyuan",
        "d/hudong/xiangyang/xjie",
        "d/hudong/xiangyang/xpailou",



        "d/hudong/xiangyang/xuanwumen",
        "d/hudong/xiangyang/xyudian",
        "d/hudong/xiangyang/yamen",
        "d/hudong/xiangyang/yaopu",
        "d/hudong/xiangyang/yingzhang",
        "d/hudong/xiangyang/ymzhengting",
        "d/hudong/xiangyang/zahuopu",
        "d/hudong/xiangyang/zhuquemen",
        "d/hudong/xiangyang/zqmnj",
        "d/hudong/xiangyang/zrdian",
});

void xyjob_1() //����׼��
{
       object obj,obj1,obj2, obj3, env;


message("channel:chat", HIY"��"HIW"��������"HIY"��"HIC"���ĵ�(Lv wende)�����������ɹŴ���ѱƽ���������͢��δ����Ԯ�����������Ǻã�\n"NOR,users());
    message("channel:chat", HIY"��"HIW"��������"HIY"��"HIC"����(Guo jing)�������㷢Ӣ����ļ������Ӣ���������������ǣ�\n"NOR,users());
    message("channel:chat", HIY"��"HIW"��������"HIY"��"HIC"�ɸ�(Meng ge)�����ιٱ��������ҷ����������ɹ���ʿ���������ޱȣ��ο���������������Ӧ�����¶��ɣ�\n"NOR,users());
    message("channel:chat", HIY"��"HIW"��������"HIY"��"HIC"���ַ���(Jinlun fawang)�������������������������������ӣ���\n"NOR,users());
message("channel:chat", HIY"��"HIW"��������"HIY"��"HIC"����(Guo jing)���ߣ����巬���ݵò�����̶��ȼ�ʶ��ԭ���ֺ��ܵ��ֶΣ�\n"NOR,users());
CHANNEL_D->do_channel( this_object(), "sys", "������սϵͳ�Ѿ�������\n"); 
if(!objectp(find_object("/d/xiangyang/damen")))
    load_object("/d/xiangyang/damen");
    obj = find_living("shuoshu laozhe");
    if(!obj || !objectp(obj)) obj= new("/d/xiangyang/npc/oldman");
    env = environment(obj);
    if(!env || file_name(env)!="/d/xiangyang/damen")
    obj->move("/d/xiangyang/damen");
    obj->set("hd_start",1); //   ��������    
CHANNEL_D->do_channel( obj, "chat", "������սϵͳ�Ѿ���������λ��ҿɵ���ݴ��Ŵ������μ�(ask laozhe about ����)��\n");    



if(!objectp(find_object("/d/hudong/xiangyang/defend")))
    load_object("/d/hudong/xiangyang/defend");
    obj1 = find_living("lv wende");
    if(!obj1 || !objectp(obj1)) obj1= new("/d/hudong/xiangyang/npc/lvwende");
    env = environment(obj1);
    if(!env || file_name(env)!="/d/hudong/xiangyang/defend")
    obj1->move("/d/hudong/xiangyang/defend");
    obj1->set("hd_start",1);                 //��ʼ����

    if(!objectp(find_object("/d/hudong/xiangyang/attack")))
    load_object("/d/hudong/xiangyang/attack");
    obj2 = find_living("meng ge");
    if(!obj2 || !objectp(obj2)) obj2= new("/d/hudong/xiangyang/npc/mengge");

    env = environment(obj2);
    if(!env || file_name(env)!="/d/hudong/xiangyang/attack")
    obj2->move("/d/hudong/xiangyang/attack");
    obj2->set("hd_start",1);



 remove_call_out("xyjob_1");
call_out("xyjob_2", 60,obj,obj1,obj2);  // ʱ�䳤һ��
}
void xyjob_2(object obj,object obj1,object obj2)
{
  if(obj) obj ->delete("hd_start");       //ֹͣ����
if(obj1) obj1 ->delete("hd_start");       //ֹͣ����
if(obj2) obj2 ->delete("hd_start");       //ֹͣ����
 message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"������ս������ʮ���ʼ��\n"NOR,users());
call_out("xyjob_3", 60);   // ʱ�䳤һ��
}

void xyjob_3()
{
string room;
int i;
int at,df;
object *ob;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);

if (df < 1)
        {
               message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"�����ؾ��߹���ս�Ƽ��ز������ɹŴ��ֻ��������̾��\n"NOR,users());
                remove_call_out("xyjob_3");
                call_out("xyjob_1", 3600);
        }
        else if (at < 1)
        {
                message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"�ɹ��ȷ��Ⱥ�Ԯδ����ֻ���ݻ����ǣ�\n"NOR,users());
                remove_call_out("xyjob_3");
                call_out("xyjob_1", 3600);
        }
        else
        {       


                message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"������ս��ʼ��˫����������������\n"NOR,users());
message("channel:chat", HIY"��"HIW"��������"HIY"��"HIC"���ĵ�(Lv wende)�������ﰡ���ɹž������ˣ���س��ţ�\n"NOR,users());

 // reset_eval_cost();

for(i=0;i<df;i++){
room = xyjob_room[random(sizeof(xyjob_room))];

    	if(!defender[i]->is_character() || defender[i]->is_corpse() || defender[i]->is_ghost()|| defender[i]->apply_condition("killer")){
    		defender[i]->delete_temp("��������");  //���ǻ���,ɱ�˷�������
    		continue;      	
 }

               	defender[i]->set_temp("��������/������ս/��Ӫ",1);
defender[i]->move(room);
    }
   for(i=0;i<at;i++){
    	if(!attacker[i]->is_character() || attacker[i]->is_corpse() || attacker[i]->is_ghost()|| attacker[i]->apply_condition("killer")){
    		attacker[i]->delete_temp("��������");  //���ǻ���,ɱ�˷�������
    		continue;      	
 }

               	attacker[i]->set_temp("��������/������ս/��Ӫ",2);
attacker[i]->move("d/hudong/xiangyang/zhangwai");
    

              
}
call_out("xyjob_4",900);

}
}

void xyjob_4()
{
string room;
int i;
int at,df;
object *ob;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
if (sizeof(attacker) > sizeof(defender))
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"��˵�ɹű������������ǣ�");
                for(i = 0; i < at; i++)
                        attacker[i]->add_temp("xyjob/attack", 1);
        }
        else
        {
                CHANNEL_D->do_channel(this_object(), "rumor", HBMAG+HIW"��˵�����ؾ�ɱ�����ɹž���");
                for(i = 0; i < df; i++)
                        defender[i]->add_temp("xyjob/defend", 1);
        }

remove_call_out("xyjob_4");
	call_out("xyjob_5", 5);

}


void xyjob_5() // ���Ž���
{

int i;
int at,df;
int exp, nexp, pot, SJ_Credit;

object *ob;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
        
        for(i = 0; i < at; i++)
        {
                exp = attacker[i]->query_temp("xyjob/attack")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*df)
                        exp = 1000 + 200*df -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                pot = exp/6 +random(exp/10);
                SJ_Credit = exp*2/400;
                attacker[i]->add("SJ_Credit",SJ_Credit);
                attacker[i]->add("combat_exp",exp);
                if(attacker[i]->query("potential") + pot > attacker[i]->query("max_pot"))
                        attacker[i]->set("potential", attacker[i]->query("max_pot"));
                else
                        attacker[i]->add("potential", pot);
                message_vision(HIW"\n$N�����"+CHINESE_D->chinese_number(exp)+
                "�㾭�飬"+ CHINESE_D->chinese_number(pot)+
                "��Ǳ�ܵĽ�����\n"+HIR+"\n$N���⻹�����"+ CHINESE_D->chinese_number(SJ_Credit)+"������ͨ��\n"NOR, attacker[i]);
                attacker[i]->add("shen",-nexp);
                message_vision(HIW"\n$N����һ��а������������\n"NOR,attacker[i]);
                attacker[i]->add("job_time/��������",1);
                attacker[i]->clear_conditions_by_type("poison");
                attacker[i]->clear_conditions_by_type("hurt");
                attacker[i]->clear_conditions_by_type("busy");
                attacker[i]->clear_conditions_by_type("zhenqi");
                attacker[i]->remove_all_killer();
                attacker[i]->dismiss_team();
                attacker[i]->clear_condition("job_busy");
                log_file("job/xyjob", sprintf("%s %s(%s)%d�ι��ǵõ�����%d��Ǳ��%d��ͨ��%d��\n",
                ctime(time())[4..19],attacker[i]->name(1),attacker[i]->query("id"),(int)attacker[i]->query("job_time/��������"),exp,pot,SJ_Credit));
        }
        for(i = 0; i < df; i++)
        {
                exp = defender[i]->query_temp("xyjob/defend")*800;
                if (exp <= 0)
                        exp = 400;
                exp += random(exp/4);
                if (exp > 1000 + 200*at)
                        exp = 1000 + 200*at -random(200);
                if (exp > 3500)
                	exp = 3400 + random(101);
                nexp = exp;
                SJ_Credit = exp*2/400;
                pot = exp/6 +random(exp/10);
                defender[i]->add("SJ_Credit",SJ_Credit);
                defender[i]->add("combat_exp",exp);
                if (defender[i]->query("potential") + pot > defender[i]->query("max_pot"))
                        defender[i]->set("potential", defender[i]->query("max_pot"));
                else
                        defender[i]->add("potential", pot);
                message_vision(HIW"\n$N�����"+CHINESE_D->chinese_number(exp)+
                "�㾭�飬"+ CHINESE_D->chinese_number(pot)+
                "��Ǳ�ܵĽ�����\n"+HIR+"\n$N���⻹�����"+ CHINESE_D->chinese_number(SJ_Credit)+"������ͨ��\n"NOR, defender[i]);
                defender[i]->add("shen",nexp);
                message_vision(HIW"\n$N���������������ˣ�\n"NOR,defender[i]);
                defender[i]->add("job_time/��������",1);
                defender[i]->clear_conditions_by_type("poison");
                defender[i]->clear_conditions_by_type("hurt");
                defender[i]->clear_conditions_by_type("busy");
                defender[i]->clear_conditions_by_type("zhenqi");
                defender[i]->remove_all_killer();
                defender[i]->dismiss_team();
                defender[i]->clear_condition("job_busy");
                log_file("job/xyjob", sprintf("%s %s(%s)%d���سǵõ�����%d��Ǳ��%d������ͨ��%d��\n",
                ctime(time())[4..19],defender[i]->name(1),defender[i]->query("id"),(int)defender[i]->query("job_time/��������"),exp,pot,SJ_Credit));
        }
        remove_call_out("xyjob_5");
remove_call_out("xyjob_1");
        call_out("xyjob_1", 1800);
        }









void xy_attackbh()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"�׻����ѱ��ɹŴ�����ƣ��ɹ��ȷ�Ӱ׻��Ž���������\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"�㱻�����ˣ�" +
		chinese_number(exp) + "��ʵս���飬" +
		chinese_number(pot) + "��Ǳ�ܡ�"+
		"���Ͱ����Ѿ�ʤ����һ���ˡ�\n"NOR);


}
call_out("boss_guo",3);
}

void xy_attackql()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"�������ѱ��ɹŴ�����ƣ��ɹ��ȷ�������Ž���������\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"�㱻�����ˣ�" +
		chinese_number(exp) + "��ʵս���飬" +
		chinese_number(pot) + "��Ǳ�ܡ�"+
		"���Ͱ����Ѿ�ʤ����һ���ˡ�\n"NOR);


}
call_out("boss_yang",3);
}
void xy_attackzq()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"��ȸ���ѱ��ɹŴ�����ƣ��ɹ��ȷ����ȸ�Ž���������\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"�㱻�����ˣ�" +
		chinese_number(exp) + "��ʵս���飬" +
		chinese_number(pot) + "��Ǳ�ܡ�"+
		"���Ͱ����Ѿ�ʤ����һ���ˡ�\n"NOR);


}
call_out("boss_huangrong",3);

}

void xy_attackxw()
{
object env,env1,env2,env3,door,door1,door2,door3;
object me;
int i;
int at,df;
int exp,pot;
object *attacker = filter_array(users(), (:$1->query_temp("��������/������ս/attack") :));
object *defender = filter_array(users(), (:$1->query_temp("��������/������ս/defend"):));
object target,target1,target2,target3;
df = sizeof(defender);
at = sizeof(attacker);
exp =200;
pot =exp;


message("channel:chat", HIY"��"HIR"ϵͳ��ʾ"HIY"��"HIC"�������ѱ��ɹŴ�����ƣ��ɹ��ȷ�������Ž���������\n"NOR,users());
for(i=0;i<at;i++){
	attacker[i]->add("combat_exp",exp);
attacker[i]->add("potential",pot);
tell_object(attacker[i],HIW"�㱻�����ˣ�" +
		chinese_number(exp) + "��ʵս���飬" +
		chinese_number(pot) + "��Ǳ�ܡ�"+
		"���Ͱ����Ѿ�ʤ����һ���ˡ�\n"NOR);


}
call_out("boss_huang",3);
}

void boss_guo()
{
// object boss = new("d/hudong/xiangyang/npc/guo");
object obj;
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"���ڴ�ʱ���Ӱ׻��ų�¥��Ծ��һ�������ӣ���������߰�Ʈ�䵱�¡�\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"����̧�۹ۿ����������������Ĺ���������һʱ���ɹŴ�����˵�����\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"����(Guo jing)���ɹ�������Ҫ���񣬴���ĳ������ȼ����ߵͣ�\n"NOR,users());
 obj = find_living("guo jing");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/guo");
obj ->move("d/hudong/xiangyang/baihumen");
}

void boss_yang()
{

object obj;
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"���ڴ�ʱ���������ų�¥��Ծ��һ�������ӣ�����ƮƮ�������ڵ��¡�\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"���˶������ƣ�����һֻ��ܿտյ���������Ӣ������ȴ˿�����\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"���(Yang guo)����������Сֶ������٣����������һ���ɹŸ��ֵľ�����\n"NOR,users());
 obj = find_living("yang guo");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/yang");
obj ->move("d/hudong/xiangyang/qinglongmen");
}

void boss_huang()
{

object obj;
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"������ʱ���������ų�¥�Ϸ�Ծ��һ�������ˣ�һ�����Ʈ�����ڵ��¡�\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"������ϸһ��������һͷ�׷����Ʈ������ͻ�Գ��϶��ּ������֮�⡣\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"��ҩʦ(Huang Yaoshi)���������������ɹ��������Ĵֱ�֮�ˣ������Բ����ۣ�\n"NOR,users());
 obj = find_living("yang guo");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/huang");
obj ->move("d/hudong/xiangyang/xuanwumen");
}

void boss_huangrong()
{

object obj;
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"���Ž��ƣ�����ȸ�ų�¥�Ϸ�Ծ��һ����Ů�ӣ�һ����£��ֳ����Ʈ���ڵ��¡�\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"������ϸһ��������ؤ��ǰ�ΰ���������������֮�ޣ����ػ�Ů��������������ü��\n"NOR,users());
message("channel:chat", HIY"��"HIR"����ս��"HIY"��"HIC"����(Huang Rong)�����ӸҶ���������ö��ȼ�ʶ��ԭ���ֺ��ܵ�Ӣ���ֶΣ�\n"NOR,users());
 obj = find_living("yang guo");
    if(!obj || !objectp(obj)) obj= new("d/hudong/xiangyang/npc/huangrong");
obj ->move("d/hudong/xiangyang/zhuquemen");
}
