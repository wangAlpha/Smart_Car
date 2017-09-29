/******************************************************************************
 *
 * Freescale Semiconductor Inc.
 * (c) Copyright 2004-2010 Freescale Semiconductor, Inc.
 * ALL RIGHTS RESERVED.
 *
 ******************************************************************************
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL FREESCALE OR ITS CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 *
 **************************************************************************//*!
 *
 * @file usb_hid.c
 *
 * @author
 *
 * @version
 *
 * @date
 *
 * @brief The file contains USB stack HID layer implementation.
 *
 *****************************************************************************/

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "usb_hid.h"    /* USB HID Class Header File */
#include "usb_devapi.h" /* USB device Header File */

/*****************************************************************************
 * Constant and Macro's
 *****************************************************************************/

/****************************************************************************
 * Global Variables
 ****************************************************************************/
/* HID endpoint info array */
static USB_CLASS_HID_ENDPOINT_DATA g_hid_endpoint_data;
/* HID Class Callback Function Pointer */
static USB_CLASS_CALLBACK g_hid_class_callback = NULL;
/* HID Class Vendor Callback Function Pointer */
static USB_REQ_FUNC       g_vendor_req_callback = NULL;
/* HID Class requests Callback Function Pointer */
static USB_CLASS_SPECIFIC_HANDLER_FUNC g_param_callback = NULL;
/*****************************************************************************
 * Local Types - None
 *****************************************************************************/

/*****************************************************************************
 * Local Functions Prototypes
 *****************************************************************************/
#ifndef COMPOSITE_DEV
static uint_8 USB_Other_Requests(uint_8 controller_ID,
                                 USB_SETUP_STRUCT *setup_packet,
                                 uint_8_ptr *data,
                                 USB_PACKET_SIZE *size);
#endif
static uint_8 USB_Map_Ep_To_Struct_Index(uint_8 controller_ID,
                                         uint_8 ep_num);

/*****************************************************************************
 * Local Variables - None
 *****************************************************************************/
uint_8 g_class_request_params[2]; /* for get/set idle and protocol requests*/

/*****************************************************************************
 * Local Functions
 *****************************************************************************/
/**************************************************************************//*!
*
* @name  USB_Map_Ep_To_Struct_Index
*
* @brief The funtion maps the endpoint number to the index of the endpoint
*        data structure
*
* @param controller_ID     : Controller ID
* @param ep_num            : Endpoint number
*
* @return index            : mapped index
*
******************************************************************************Microsoft-Windows-ServerCore-WowOptional-key-minkernel-WOW64-Package~31bf3856ad364e35~amd64~zh-CN~0.0.0.0       ����vk;   �         Package_3080_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����@��� �����vk<   �         Package_4243_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_4404_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    ����vk;   �         Package_3072_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����X�ؐ0�����8����@����    ���� �X����`����hbin �                       H���nk  v�ڋ�    V�        ��������   ���d�����  �     x          d   Microsoft-Windows-ServerCore-WowOptional-key-minkernel-WOW64-Package~31bf3856ad364e35~amd64~~0.0.0.0    ����vk<   �         Package_4235_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_4396_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    P���nk  I4����    V�        ��������   ���d�����  �     x          ^   Microsoft-Windows-ServerCore-WowOptional-onecore-WOW64-Package~31bf3856ad364e35~amd64~~0.0.0.0  ����vk:   �       �Package_917_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1��Y�����vk:   �       �Package_919_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1��Y�����vk<   �       �Package_1068_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15�5�����vk<   �       �Package_1072_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15�5�����vk<   �         Package_1130_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    ����vk<   �         Package_1135_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  `c�    V�        ��������   ���d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-onecoreuap-WOW64-Package~31bf3856ad364e35~amd64~~0.0.0.0       ����vk;   �         Package_1132_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����vk<   �         Package_1381_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_1382_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_1383_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_1451_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    ����vk<   �         Package_1452_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    ����vk<   �         Package_1453_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    P���nk  �Qc݋�    V�        ��������   p��d�����  �     x          `   Microsoft-Windows-ServerCore-WowOptional-printscan-WOW64-Package~31bf3856ad364e35~amd64~~0.0.0.0����vk<   �         Package_5064_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    �������    ����vk<   �         Package_5326_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    @���nk  �v����    V�        ��������   ��d�����  �     x          l   Microsoft-Windows-ServerCore-WowOptional-sdktools-WOW64-onecore-Package~31bf3856ad364e35~amd64~zh-CN~0.0.0.0    ����vk:   �         Package_989_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1      ������ �X�����vk<   �         Package_1150_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_1216_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  7K㿋�    V�        ��������   ���d�����  �     x          g   Microsoft-Windows-ServerCore-WowOptional-sdktools-WOW64-onecore-Package~31bf3856ad364e35~amd64~~0.0.0.0����vk<   �       �Package_1037_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15�E�����h�Л    ����vk<   �       �Package_1098_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10�W�H���nk  [��׋�    V�        ��������   8��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~ar-SA~0.0.0.0�(�����vk<   �         Package_3655_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ������H�    ����vk<   �       �Package_3813_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10��H���nk  ��׋�    V�        ��������   ���d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~bg-BG~0.0.0.0       ����vk<   �         Package_3658_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����X���    ����vk<   �         Package_3816_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  -.�׋�    V�        ��������   П�d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~cs-CZ~0.0.0.0       ���� �x�Р�����8�    ����H�����hbin �                       ����vk;   �       �Package_2661_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1(|�����vk<   �         Package_3661_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �       �Package_3819_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10��H���nk  �}�׋�    V�        ��������   ���d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~da-DK~0.0.0.0       ����vk<   �         Package_3664_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_3822_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  �B�׋�    V�        ��������   ��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~de-DE~0.0.0.0       ����vk;   �         Package_2666_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����vk<   �       �Package_3667_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.158n�����vk<   �         Package_3825_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  /��׋�    V�        ��������   `��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~el-GR~0.0.0.0       ����vk<   �         Package_3670_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    �����p�    ����vk<   �         Package_3828_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  �V�׋�    V�        ��������   ئ�d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~en-GB~0.0.0.0       ����vk<   �       �Package_3673_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.158n��������    ����vk<   �         Package_3831_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  ���׋�    V�        ��������   P��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~en-US~0.0.0.0       ����vk;   �         Package_2673_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ������`�������vk<   �         Package_3676_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_3834_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  �V
؋�    V�        ��������    ��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~es-ES~0.0.0.0       ����vk;   �         Package_2676_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����ȩ0�������vk<   �       �Package_3679_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.158n�����vk<   �         Package_3837_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  �؋�    V�        ��������   ��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~es-MX~0.0.0.0       ����vk<   �         Package_3682_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ������ �    ����vk<   �         Package_3840_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  ܺ%؋�    V�        ��������   h��d�����  �     x          a   Microsoft-Windows-ServerCore-WowOptional-shell-WOW64-Package~31bf3856ad364e35~amd64~et-EE~0.0.0.0ؤpؤ����vk<   �       �Package_3685_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15(������x�    ����vk<   �         Package_3843_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10              /* [OUT] Size to be returned*/
)
{
    uint_8 index;
    uint_8 status = USBERR_INVALID_REQ_TYPE;
    uint_8 rpt_buf[REPORT_SIZE];/* buffer to send in case of get report req */
    *((uint_32_ptr)rpt_buf) = 0;
    if ((setup_packet->request_type & USB_REQUEST_CLASS_MASK) ==
        USB_REQUEST_CLASS_CLASS) {
        /* class request so handle it here */
        /* index == 0 for get/set idle, index == 1 for get/set protocol */
        index = (uint_8)((setup_packet->request - 2) &
                         USB_HID_REQUEST_TYPE_MASK);
        status = USB_OK;
        /* point to the data which comes after the setup packet */
        *data = ((uint_8 *)setup_packet) + USB_SETUP_PKT_SIZE;
        *size = 0;
        /* handle the class request */
        switch (setup_packet->request) {
        case USB_HID_GET_REPORT_REQUEST :
            /*set the data pointer to the buffer to send */
            *data = &rpt_buf[0];
            if (*size > REPORT_SIZE) {
                *size = REPORT_SIZE;
            }
            break;
        case USB_HID_SET_REPORT_REQUEST :
            for (index = 0; index < REPORT_SIZE; index++) {
                /* copy the data sent by host in the buffer */
                rpt_buf[index] = *(*data + index);
            }
            break;
        case USB_HID_GET_IDLE_REQUEST :
            /* point to the current idle rate */
            *data = &g_class_request_params[index];
            *size = CLASS_REQ_DATA_SIZE;
            break;
        case USB_HID_SET_IDLE_REQUEST :
            /* set the idle rate sent by the host */
            g_class_request_params[index] = (uint_8)((setup_packet->value
                                                      & MSB_MASK) >> HIGH_BYTE_SHIFT);
            break;
        case USB_HID_GET_PROTOCOL_REQUEST :
            /* point to the current protocol code
                        0 = Boot Protocol
                        1 = Report Protocol*/
            *data = &g_class_request_params[index];
            *size = CLASS_REQ_DATA_SIZE;
            break;
        case USB_HID_SET_PROTOCOL_REQUEST :
            /* set the protocol sent by the host
                         0 = Boot Protocol
                         1 = Report Protocol*/
            g_class_request_params[index] = (uint_8)(setup_packet->value);
            break;
        default :
            break;
        }
        if (g_param_callback != NULL) {
            /*
               handle callback if the application has supplied it
               set the size of the transfer from the setup packet
            */
            *size = (USB_PACKET_SIZE)setup_packet->length;
            /* notify the application of the class request.
               give control to the application */
            status = g_param_callback(setup_packet->request,/* request type */
                                      setup_packet->value,
                                      setup_packet->index, /* Application needs to know which Interface is being communicated with */
                                      data,/* pointer to the data */
                                      size);/* size of the transfer */
        }
    }
    else if ((setup_packet->request_type & USB_REQUEST_CLASS_MASK) ==
             USB_REQUEST_CLASS_VENDOR) {
        /* vendor specific request  */
        if (g_vendor_req_callback != NULL) {
            status = g_vendor_req_callback(controller_ID, setup_packet, data,
                                           size);
        }
    }
    return status;
}

/*****************************************************************************
 * Global Functions
 *****************************************************************************/

/**************************************************************************//*!
 *
 * @name  USB_Class_HID_Init
 *
 * @brief   The funtion initializes the Device and Controller layer
 *
 * @param   controller_ID               : Controller ID
 * @param   hid_class_callback          : HID Class Callback
 * @param   vendor_req_callback         : Vendor Request Callback
 * @param   param_callback              : Class requests Callback
 *
 * @return status:
 *                        USB_OK        : When Successfull
 *                        Others        : When Error
 *
 ******************************************************************************
 *This function initializes the HID Class layer and layers it is dependent on
 *****************************************************************************/
uint_8 USB_Class_HID_Init(
    uint_8    controller_ID,                /* [IN] Controller ID */
    USB_CLASS_CALLBACK hid_class_callback,  /* [IN] HID Class Callback */
    USB_REQ_FUNC       vendor_req_callback, /* [IN] Vendor Request Callback */
    USB_CLASS_SPECIFIC_HANDLER_FUNC param_callback
    /* [ IN] HID Class requests Callback */
)
{
    uint_8 index, status = USB_OK;
    USB_ENDPOINTS *ep_desc_data = (USB_ENDPOINTS *)
                                  USB_Desc_Get_Endpoints(controller_ID);
#ifndef COMPOSITE_DEV
    /* Initialize the device layer*/
    status = _usb_device_init(controller_ID, NULL,
                              (uint_8)(ep_desc_data->count + 1), TRUE);
    if (status == USB_OK) {
        /* Initialize the generic class functions */
        status = USB_Class_Init(controller_ID, USB_Class_Hid_Event,
                                USB_Other_Requests);
        if (status == USB_OK) {
#endif
            g_hid_endpoint_data.count = ep_desc_data->count;
            for (index = 0; index < ep_desc_data->count; index++) {
                g_hid_endpoint_data.ep[index].endpoint =
                    ep_desc_data->ep[index].ep_num;
                g_hid_endpoint_data.ep[index].type =
                    ep_desc_data->ep[index].type;
                g_hid_endpoint_data.ep[index].bin_consumer = 0x00;
                g_hid_endpoint_data.ep[index].bin_producer = 0x00;
            }
            /* save the HID class callback pointer */
            g_hid_class_callback = hid_class_callback;
            /* save the vendor request callback pointer */
            g_vendor_req_callback = vendor_req_callback;
            /* Save the callback to ask application for class specific params*/
            g_param_callback = param_callback;
#ifndef COMPOSITE_DEV
        }
    }
#endif
    return status;
}

/**************************************************************************//*!
 *
 * @name  USB_Class_HID_DeInit
 *
 * @brief   The funtion de-initializes the Device and Controller layer
 *
 * @param   controller_ID               : Controller ID
 *
 * @return status:
 *                        USB_OK        : When Successfull
 *                        Others        : When Error
 *
 ******************************************************************************
 *This function de-initializes the HID Class layer
 *****************************************************************************/
uint_8 USB_Class_HID_DeInit
(
    uint_8 controller_ID              /* [IN] Controller ID */
)
{
    uint_8 status = USB_OK;
#ifdef COMPOSITE_DEV
    UNUSED(controller_ID)
#endif
    /* free the HID class callback pointer */
    g_hid_class_callback = NULL;
    /* free the vendor request callback pointer */
    g_vendor_req_callback = NULL;
    /* free the callback to ask application for class specific params*/
    g_param_callback = NULL;
#ifndef COMPOSITE_DEV
    /* Call common class deinit function */
    status = USB_Class_DeInit(controller_ID);
    if (status == USB_OK)
        /* Call device deinit function */
    {
        status = _usb_device_deinit();
    }
#endif
    return status;
}

/**************************************************************************//*!
 *
 * @name  USB_Class_HID_Send_Data
 *
 * @brief This fucntion is used by Application to send data through HID class
 *
 * @param controller_ID     : Controller ID
 * @param ep_num            : Endpoint number
 * @param app_buff              Package_3742_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_3900_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  U+Zً�    V�        ��������   �o�d�����  �     x          d   Microsoft-Windows-ServerCore-SKU-Foundation-WOW64-shell-Package~31bf3856ad364e35~amd64~th-TH~0.0.0.0    ����vk<   �         Package_3744_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����(o�o    ����vk<   �         Package_3902_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    �����p0q�q����(�hbin p                       H���nk  �iً�    V�        ��������   �o�d�����  �     x          d   Microsoft-Windows-ServerCore-SKU-Foundation-WOW64-shell-Package~31bf3856ad364e35~amd64~tr-TR~0.0.0.0    ����vk;   �         Package_2728_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����vk<   �         Package_3746_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_3904_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk   dwً�    V�        ��������   �r�d�����  �     x          d   Microsoft-Windows-ServerCore-SKU-Foundation-WOW64-shell-Package~31bf3856ad364e35~amd64~uk-UA~0.0.0.0    ����vk<   �         Package_3748_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    �����r s    ����vk<   �         Package_3906_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  ���ً�    V�        ��������   ht�d�����  �     x          d   Microsoft-Windows-ServerCore-SKU-Foundation-WOW64-shell-Package~31bf3856ad364e35~amd64~zh-CN~0.0.0.0�1�����vk;   �         Package_2731_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1     ����txt�t����vk<   �         Package_3750_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_3908_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10    H���nk  mӗً�    V�        ��������   8v�d�����  �     x          d   Microsoft-Windows-ServerCore-SKU-Foundation-WOW64-shell-Package~31bf3856ad364e35~amd64~zh-TW~0.0.0.0�1�����vk;   �       �Package_2733_for_KB3213986~31bf3856ad364e35~amd64~~10.0.1.1H������uHv�v����vk<   �         Package_3752_for_KB4025339~31bf3856ad364e35~amd64~~10.0.1.15    ����vk<   �         Package_3910_for_KB4034658~31bf3856ad364e35~amd64~~10.0.1.10