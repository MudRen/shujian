// shiye.c modified by fengyue 2008.10.19

#include <ansi.h>
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define KUANGSHI    "/d/zhiye/obj/kuangshi" //��
#define BULIAO    "/d/zhiye/obj/buliao" //����

inherit NPC;
int ask_me(object who);

void create()
{
	set_name("����ˮ", ({ "wang huaishui", "wang" }));
	set("title", "�Ӿ�Ʒʦү");
	set("gender", "����");
	set("age", 57);
	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen", -1);
	set("inquiry", ([
//                 "ٺ»" : (: ask_me :),
	]));
	setup();
	carry_object("/clone/armor/cloth")->wear();
	carry_object("/clone/armor/shoes")->wear();
}

int ask_me(object who)
{
        object me = this_player();
        object obj;
        int times,gold,gold2,gold3,tb2,exp,tb,exp1;

        string str = "";
       int i = random(3);
        times = (int)me->query("job_time/�ٸ�",1);

        if ( times<49 ){
		command("say ��ûΪ��͢����ʲ����������Ҫٺ»��\n");
		return 1;
	}
        if ( times > 15000 ){
		command("say ���²����Ǹ�֪��ʦү�����ỹ�Ҹ�����ٺ»�أ�\n");
		command("flatter " + me->query("id"));
		return 1;
        }


if( (int)me->query("gf_gives") < (int)me->query("age") && time()- me->query("gf_job_time")>604800 ) 
{

    exp = times * 1500;
    exp1 = times * 1000;
    gold=times * ( 50 + random(30) );
    gold2=gold/10000;
    gold3=gold/20000;
    tb = random(times /50) + 1; 
    tb2 = random(times /50)+1; 
me->set("gf_job_time",time());

if (me->query_temp("mark/huilu"))
           {
			command("hehe " + me->query("id"));
                        message_vision("����ˮ��ͷ������˵������λ"+RANK_D->query_respect(me)+"������, �Ժ������������¡�\n",me);
	//		command("give "+me->query("id")+" gold");
			me->delete_temp("mark/huilu");
                        me->set("gf_gives",(int)me->query("age"));

                        me->add("balance", gold);
                        me->add("SJ_Credit", tb );
                        me->add("combat_exp", exp);

                 message_vision(HIC"����ˮ�ó�һ���̲����ĵݸ�"+me->query("name")+"˵�������̲��������ݹ�Ա���ٺ»����,��λ"+RANK_D->query_respect(me)+",���Լ����ɡ�\n",me);
                 switch(i) {
                        case 0:         
                                obj = new (KUANGSHI);
                                obj->set_level(8+random(2));
               
                                break;    
                         case 1:         
                                 obj = new (BULIAO);
                                obj->set_level(8+random(1));
               
                                break;   
                                 
                         case 2:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(4+random(1));
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;   
                                break;  
                        default:return 1;
                           }
                           obj->move(me);
    
              message_vision(HIC""+me->query("name")+""HIC"����Ӧ��ٺ»Ϊ�ƽ�" + CHINESE_D->chinese_number(gold2) + "��,ͨ��" + CHINESE_D->chinese_number(tb) + "����\n"NOR, me);  
              tell_object(me,HIY"�ر�ν���"+obj->name()+""HIY"��һ"+obj->query("unit")+"��\n"NOR);
              tell_object(me,HIY"������" + CHINESE_D->chinese_number(exp) + "�㾭�齱����\n"NOR);



              if(times >= 5000 && random(10) > 5 )
{
  message_vision(HIC"����"+me->query("name")+""HIC"�����ڷܣ��ɼ��Ȼ�������ȡ�"HIR"������"HIC"���ƺţ�����������\n"NOR, me);  
  tell_object(me,HIY"���������" + CHINESE_D->chinese_number(exp) + "�㾭�齱����\n"NOR);
                      me->add("combat_exp", exp);
                      me->set("title", HIR"������"NOR);


}



			return 1;
	}

//�����������¸
		command("look " + me->query("id"));
		command("hmm " + me->query("id"));
		command("say ���£����ҿ�һ����\n");
           
             message_vision(WHT"����ˮװģ�������ó�һ���̲����Ŀ��˿���\n"NOR, me);
    message_vision(HIC"����ˮ˵����"+me->query("name")+"����Ӧ��ٺ»Ϊ�ƽ�" + CHINESE_D->chinese_number(gold3) + "��,ͨ��" + CHINESE_D->chinese_number(tb2) + "����\n"NOR, me); 
                        me->add("balance", gold/2);
                        me->add("SJ_Credit", tb2);
                        me->add("combat_exp", exp1);

 tell_object(me,HIY"������" + CHINESE_D->chinese_number(exp1) + "�㾭�齱����\n"NOR);
		
 message_vision(WHT""+me->query("name")+"��Լ������Ŀ���󲻴�԰���\n"NOR, me);
		me->set("gf_gives",(int)me->query("age"));
		return 1;
	}

        command("say û��ʱ���أ���ʲ��ٺ»��!\n");

        return 1;
}

int accept_object(object me, object obj)
{
        int times;
        times=me->query("job_time/�ٸ�",1);

        if (!me->query("job_time/�ٸ�")){
		command("say ��Ե�޹��������¸�ң�\n");
		return 1;
        }
        if(obj->query("money_id")){
                if(obj->value() >= times*10){
			command("hehe "+me->query("id"));
			command("whisper "+me->query("id")+" ��ͷ��İɣ���ͷ�һ�úù�����ģ�");
			me->set_temp("mark/huilu",1);
			return 1;
		}
		command("say ��ô��Ǯ�ܸ�ʲ�᣿��������ȥһ������Ժ���أ�");
		return 1;
        }
	command("say �����"+obj->name()+"�����ң���ʲ���ã���");
	return 0;
}

void destroy (object obj)
{
	destruct(obj);
	return;
}
