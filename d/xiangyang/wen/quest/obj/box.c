// By Spiderii@yt bt��Ʒ
#include <ansi.h>
#define BOOK    "/clone/gift/book"      //��
#define MIC     "/clone/gift/danwan"    //ҩ
#define MON     "/clone/gift/money"     //Ǯ
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define MIJI    "/u/yueying/jinshe/obj/jszf-book"//�ؼ�
inherit SPEC;
void create()
{
        set_name(HIW"���ر���"NOR, ({ "box","baohe" }) );
        set_weight(10);
                set("unit", "��");
                set("long", "һ�����ص���ʺ��ӡ�\n�Ǵ�˵���������Ա(action)���䷲��ı�������ܸ����Ǵ������˺Ͷ��˵�ħ��֮�С�\n�ǲ��Ǿ����������ջ��أ��ǾͿ�򿪣�open�����ɡ�����\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/baohe");
                set("desc","��˵�򿪺��ӻ��б�����֡�");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_open", "open");
}

int do_open(string arg)
{        
       object me = this_player();
       object obj;
       string str = "";
       int i = random(4);

       if(arg!="box" && arg!="baohe")
                    return notify_fail("��Ҫ��ʲô?\n");

       switch(i) {
                        case 0:         
                                obj = new (BOOK);
                                str = "��";  
                                break;
                        case 1: 
                                obj = new (MIC);
                                if (random(me->query_kar()) > 29) {
                                        obj->set("secret_obj",1);
                                        str = "��Ʒ";
                                }
                                str += "ҩ";     
                                break;
                        case 2:         
                                obj = new (MON);
                                str = "Ǯ"; 
                                break;
                        case 3:
                                      obj = new (MIJI);
                                      str = "�ؼ�";
                                      break;
                        default:return 0;
                }
        obj->move(this_player());
        message_vision(HIW"$N�ӱ����еõ���һ"+obj->query("unit")+obj->name()+"��\n\n"NOR,me); 
        destruct(this_object());
        return 1;
                
}

