// By action@sjcb bt��Ʒ
#include <ansi.h>
#define BOOK    "/clone/gift/book"      //��
#define MIC     "/clone/gift/danwan"    //ҩ
#define MON     "/clone/gift/money"     //Ǯ
#define JADE    "/d/zhiye/obj/othermaterial" //��
#define MIJI    "/d/zhiye/obj/othermaterial" //��
inherit SPEC;
void create()
{
        set_name(HIY"��"HIC"��"HIM"��"HIR"��"HIW"��"NOR, ({ "yue bing","yuebing" ,"bing"}) );
        set_weight(10);
                set("unit", "��");
                set("long", "һ�������������±���\n�Ǵ�˵������և(action)�����ģ��������п��ܸ�������޴�ϲ��\n�ǲ��Ǿ����������ջ��أ��ǾͿ쳢��pinchang�����ɡ�����\n");
                set("value", 0);
                set("material", "wood");
                set("no_drop", "�������صĶ�����ô������Ҷ��ء�\n");
                set("no_get", "�������������뿪�Ƕ���\n");
                set_weight(100);
                set("value",3000000);
                set("treasure",1);
                set("degree",1);
                set("flag","spec/yuebing");
                set("desc","��˵�������ͻ���������������֡�");
                set("credit",150);    

       setup();
}
void init()
{
        add_action("do_pinchang", "pinchang");
}

int do_pinchang(string arg)
{        
       object me = this_player();
       object obj;
       string str = "";
       int i = random(2);

       if(arg!="bing" && arg!="yuebing")
                    return notify_fail("��Ҫ��ʲô?\n");

       switch(i) {
                        case 0:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;    
                         case 1:         
                                obj = new (JADE);
                               
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;      
                         case 2:         
                                obj = new (JADE);
                                
                                        obj->set("secret_obj",1);
                                        obj->set_level(5);
                                        str = "��Ʒ";
                                
                                str += "��";  
                                break;   
                                break;                                      
                     
                        default:return 1;
                }
        obj->move(this_player());
        message_vision(HIW"$N���±������еõ���һ"+obj->query("unit")+obj->name()+"��\n\n"NOR,me); 
        destruct(this_object());
        return 1;
                
}

