// �Դ�����������Ŀ
// by hongba

inherit NPC;
#include <ansi.h>

int ask_duilian(string arg);
void init()
{
        add_action("do_guess", "answer");
}

void create()
{
 set_name(HIC"�Դ���"NOR, ({"dui chuanchang", "dui", "chuanchang" }) );
set("title", BRED HIW"�Ա������޵���"NOR);

        set("gender", "����" );
        set("age", 60+random(10));
        set("long", HIW"���Ǹ�����ʫ������������ó��Զ����������(ask dui about �Զ���)��
Ȼ����(answer)���ش�������\n"NOR);

       set("inquiry", ([
 "�Զ���"          : (: ask_duilian :),
 ]));


	setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}




int ask_duilian(string arg)
{
object me;
string answer;
me = this_player();
if (!me)
return 0;

if (me->query_temp("askduilian"))
{
 command("say ���Ȱ����������˵��");
return 1;
}
switch (random(17)) {
		case 0:
			command("say ���ڻ��Ľ�ܱ׳?");
			me->set_temp("answer","��ů���Ʋ�ľ��");
			break;
		case 1:
			command("say ��������������?");
			me->set_temp("answer","ȵ��֦ͷ������");
			break;
		case 2:
			command("say ��ˮǧɽƾ��Ծ��");
			me->set_temp("answer","����ĺ�������");
			break;
		case 3:
			command("say ϲ������ݷ�����");
me->set_temp("answer","Ը�����ҵ����");
			
			break;
		case 4:
			command("say �������������");
me->set_temp("answer","ϲ������������");
			
			break;
		case 5:
			command("say �������Ѱ���ã�");
me->set_temp("answer","��𿳪��Ϸ����");
			answer = "��𿳪��Ϸ����";
			break;
		case 6:
			command("say ������ϲ��������");
me->set_temp("answer","���ô�����¹�");
			
			break;
		case 7:
			command("say ϲл���������ڣ�");
me->set_temp("answer","Цӭ����������");
			
			break;
		case 8:
			command("say �����±�ǧ����");
me->set_temp("answer","��ݺ��ϲ��ʱ��");
			
			break;


case 9:
			command("say ����˻�磬���µ�Ӱ���ؽ�����ɳ���������������ң�");
me->set_temp("answer","����綹���ž�����������ǧɽ·ת����Ω�����Ӿ�");
			
			break;

case 10:
			command("say ٯ���������ӵͻأ����ˮ���̹�������");
me->set_temp("answer","����۲У��⻨�����һ�γգ�Եϵ����");
			
			break;

case 11:
			command("say ���ұ���Σ���񲻸ġ���ǧ��������ƾ˭�Խ���");
me->set_temp("answer","�����ռ���������Ȼ��ʮ������ȣ�Ϊ������");
			
			break;
case 11:
			command("say ����ɣ������ǣ�һҹ�̻�һҹѩ��");
me->set_temp("answer","̫���ۣ����Ҷ����������°�����");
			
			break;
case 12:
			command("say �������ж����������Ͻ���ɣ���������ñ�����");
me->set_temp("answer","���߲���Ů������������Ǭ����Ҳ��ִ�ʻ���ü");
			
			break;
case 13:
			command("say ��Сͨ�ԣ��������������Σ�");
me->set_temp("answer","�ɸ�����Цɷ��ԭ��¹��");
		
			break;
case 14:
			command("say ˵ʲô������������ҵ��ͼ���ɣ������ǣ�ǧ�ַ��̣�Ұ�ް׹ǣ�");
me->set_temp("answer","ͽ���˶�ת���ƣ����ž��ۣ��ܣ�ֻ���ã���ɽ���գ�һͳ����");
			
			break;


case 15:
			command("say ������򹷽�������������ʿ���˼��м���");
me->set_temp("answer","ɳ����������²�������Ӣ�ۣ����ϴ��");
			
			break;
case 16:
			command("say һ��֮��������أ�׷�������ӣ�");
me->set_temp("answer","����Ψ�𣬺��հ׹ǣ���Ͷ�����");
			
			break;
case 17:
			command("say ��ָ����,�����������£�");
me->set_temp("answer","�ٵ�һ�죬���շ��������");
			
			break;



			}
me->set_temp("askduilian",1);
return 1;
}
int do_guess(string arg)
{
        int c;
        int i;

       object me = this_player();
       c = 1+random(2);
        if(!arg)
        return 0;
if(!me->query_temp("askduilian"))
{
command("say �����Ҫ��Ŀ��ô��");
return 1;
}

if (arg != me->query_temp("answer")) {
message_vision("$Nɵ������ǰ�Ե���"HIR""+arg+"��\n"NOR, me);
command("shake " + me->query("id")); 
 command("say ���Բ��ԣ���������Ե�̫û�Ļ�");
//    me->delete_temp("answer");
return 1;
}

 else {

                me->add("SJ_Credit", c);
  message_vision("$N������ǰ�������к��ѣ������Ҷԣ�"HIY""+me->query_temp("answer")+"��\n"NOR, me);
             
 command("say �ţ��ܺúܺã��Եĺܹ����");
                write(HIG "������"HIR""+CHINESE_D->chinese_number(c)+""NOR""HIG"���齣ͨ����\n" NOR, me);
            
me->delete_temp("answer");
me->delete_temp("askduilian");
             return 1;

        }



}
